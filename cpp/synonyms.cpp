#include "synonyms.h"
#include "helpers.h"

double norm(const map<string, int>& mp) {
    // Return the norm of a vector stored as a dictionary,
    // as described in the instructions.

    double sumOfSquares = 0.0;
    for (map<string, int>::const_iterator it = mp.begin(); it != mp.end(); ++it)
    {
        sumOfSquares += pow(it->second, 2);
    }

    return sqrt(sumOfSquares);
}

double cosineSimilarity(const map<string, int>& mp1, 
                        const map<string, int>& mp2) {
    // Return the cosine similarity of vectors mp1 and mp2
    // stored as dictionaries as described in the handout for Project 2.

    int dotProduct = 0.0; // floating point to handle large numbers
    map<string, int>::const_iterator match;
    for (map<string, int>::const_iterator it = mp1.begin(); it != mp1.end(); ++it)
    {
        match = mp2.find(it->first);
        // if match found
        if (match != mp2.end()) {
            dotProduct += it->second * match->second;
        }
    }

    return double(dotProduct) / (norm(mp1) * norm(mp2));
}

vector<vector<string> > getSentenceLists(stringstream& ss) {

    vector<vector<string> > allSentences;
    // Read in string. 

    vector <string> sentence;

    size_t start = 0;
    string w = "";
    // Position where sentence ends
    size_t endPos = 0;
    // Position where word is divided by punctuation
    size_t split = 0;
    
    // Class A punctuation ".", "?", or "!"
        // will end String
    string A = ".?!";
    // Class B punctuation ",","-","--",":",";","!","?",".", "'", "“", "”"
        // will split word
    string B = ",--:;'“”\"";

    OUTER:while (ss >> w) {
        toLowerCase(w);
        start = 0;
        endPos = w.find_first_of(A, 0);
        split = w.find_first_of(B, 0);
        // found Class B
        while (split != string::npos) {
            sentence.push_back(w.substr(start, split));
            // Check if split is at end of w
            if (split+1 < w.length()) {
                // and then if there are letters after w
                if (isalpha(w.at(split+1))) {
                    start = split + 1;
                    split = w.find_first_of(B, start);
                    continue;
                }
            }
            // Word is done, move on to next one
            goto OUTER;
        }
        // found Class A
        if (endPos != string::npos) {
            // cut off word at punctuation and add to vector
            sentence.push_back(w.substr(0, endPos));
            // Insert sentence and reset vector
            allSentences.push_back(sentence);
            sentence.clear();
        }
        // Word is done
        else {
            // place word into vector
            sentence.push_back(w);
        }
    }

    return allSentences;

}


vector<vector<string> > getSentenceListFromFiles(
                                                const vector<string>& filenames
                                                ) {

    vector<vector<string> > allText;
    vector<vector<string> > newSentences;
    ifstream iFS;
    
    for (size_t i = 0; i < filenames.size(); i++) {
        iFS.open(filenames.at(i));
        if (!iFS) {
            cout << "Failed to open " << filenames[i] << endl;
            return allText;
        }

        // Read file into stringstream
        stringstream buffer;
        buffer << iFS.rdbuf();

        // Send stringstream to get sentence list for book
        newSentences = getSentenceLists(buffer);
        // Concatenate vector
        allText.insert(allText.end(), newSentences.begin(),
                            newSentences.end());
        newSentences.clear();
        // on to next file
        iFS.close();
    }

    return allText;
}

map<string, map<string, int> > buildSemanticDescriptors(
                                        vector<vector<string> >& sentences
                                        ) {

    map<string, map<string, int> > d;
    map<string, int> wd;
    string w = "";

    // For every sentence
    for (size_t i = 0; i < sentences.size(); i++) {
        // Create a semantic description recording the words in each sentence
        for (size_t j = 0; j < sentences[i].size(); j++) {
            w = sentences[i][j];
            addToMap(wd, w);
        }
        // Add semantic descripton to dictionary on a word-by-word basis
        // Because this is done for every word, we need another loop
        for (map<string, int>::iterator it = wd.begin(); it != wd.end(); ++it) {

            // Insert sem. desc. to dictionary
            if (d.count(it->first)) { // If word already in dictionary
                mergeMaps(d.at(it->first), wd, it->first); 
            }
            else { // Need to add word to dictionary
                d.emplace(it->first, wd); 
            }

        }

        // Wipe wd to reuse for next sentence
        wd.clear();
    }

    return d;
}

string mostSimilarWord(string word, vector<string> choices, 
                       map<string, map<string, int> >& semanticDescriptors) {
    string wordMostSimilar = "";

    // Check word is in dictionary

    // Find semantic similarity for each word in vector choices
    double bestSim = -1;
    double coSim = 0;
    size_t bestIndex = 0;

    for (size_t i = 0; i < choices.size(); i++) {
        if (!semanticDescriptors.count(choices[i])) {
            // Not in sem. desc....skip word
            continue;
        }
        coSim = cosineSimilarity(semanticDescriptors.at(word),
                                 semanticDescriptors.at(choices[i]));
        // Decide which of all words has the best similarity
        if (coSim > bestSim) {
            bestSim = coSim;
            bestIndex = i;
        }

    }

    wordMostSimilar = choices[bestIndex];

    return wordMostSimilar;
}

double runSimilarityTest(string fileName,
                         map<string, map<string, int> >& semanticDescriptors) {
    // See handout on how to structure test file
    double accuracy = 0;
    ifstream iFS(fileName);
    if (!iFS) {
        cout << "cannot open test file" << endl;
        return -1;
    }

    string prompt = "";
    string answer = "-";
    string choice = "---";
    vector<string> options;

    int questions = 0;
    string line;
    istringstream is;
    int correct = 0;
    while (getline(iFS, line)) {
        is.str(line);
        // Get prompt and answer
        is >> prompt >> answer;
        // Get possible answers
        while (is >> choice) {
            options.push_back(choice);
        }

        // Get computer's response
        // first check if word is in dictionary
        if (!semanticDescriptors.count(prompt)) {
            cout << prompt << " is not in library :( try another word" << endl;
            questions--;
        }

        // Then see if computer can guess right or wrong
        else {
            string response = mostSimilarWord(prompt, options, semanticDescriptors);
            if (answer.compare(response) == 0) {
                cout << "Right: " << prompt << endl;
                correct++;
            }

            else {
                cout << "Wrong: " << prompt << endl;
            }
        }

        is.clear();
        options.clear();
        questions++;
    }

    // My ghetto try catch block
    if (questions != 0) {
        accuracy = correct / (double)questions;
    }

    return accuracy;
}