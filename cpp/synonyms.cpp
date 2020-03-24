#include "synonyms.h"
#include "parsing.h"

double norm(const vector<int>& vec) {
    // Return the norm of a vector stored as a dictionary,
    // as described in the instructions.

    int sumOfSquares = 0;
    for (int i = 0; i < vec.size(); i++) {
        sumOfSquares += vec[i] * vec[i];
    }

    return sqrt(double(sumOfSquares));
}

double cosineSimilarity(const vector<int>& vec1, const vector<int>& vec2) {
    // Return the cosine similarity of sparse vectors vec1 and vec2,
    // stored as dictionaries as described in the handout for Project 2.

    int matchIndex = 0;
    int dotProduct = 0.0; // floating point to handle large numbers
    for (size_t i = 0; i < vec1.size(); i++) {
        // find where vec1[i] is in vec2, if at all
        matchIndex = findInVec(vec2, vec1[i]);
        // if match found
        if (matchIndex != -1) {
            dotProduct += vec1[i] * vec2[matchIndex];
        }
    }

    return double(dotProduct) / (norm(vec1) * norm(vec2));
}

vector<vector<string> > getSentenceLists(stringstream& ss) {

    vector<vector<string> > allSentences;
    // Read in string. 

    string word = "";
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
    // Class B punctuation ",","-","--",":",";","!","?",".", "'", "\""
        // will split word
    string B = ",--:;'\"";

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
                mergeMaps(d[it->first], wd, it->first); 
            }
            else { // Need to add word to dictionary
                d.emplace(it->first, wd); 
                d[it->first].erase(it->first); // Remove duplicates 
            }
        }

        // Wipe wd to reuse for next sentence
        wd.clear();
    }

    return d;
}

/*
string mostSimilarWord(string word, vector<string> choices, map<string, int> semanticDescriptions);

    return wordMostSimilar;
}

double runSimilarityTest(string fileName, map<string, int> semanticDescriptions) {

    return accuracy;
}
*/