#include "synonyms.h"

// TODO find out what cpp equivalent is of vec
double norm(vector<int> vec) {
    /*
    Return the norm of a vector stored as a dictionary,
    as described in the instructions.
    */

    double sumOfSquares = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        sumOfSquares += vec[i] * vec[i];
    }

    return sqrt(double(sumOfSquares));
}

double cosineSimilarity(vector<int> vec1, vector<int> vec2) {
    /*
    Return the cosine similarity of sparse vectors vec1 and vec2,
    stored as dictionaries as described in the handout for Project 2.
    */

    double dotProduct = 0.0; // floating point to handle large numbers
    for (size_t i = 0; i < vec1.size(); i++) {
        vector<int>::iterator it = find(vec2.begin(), vec2.end(), vec1[i]);
        if (it != vec2.end()) {     // TODO if vec1[i] in vec2 
            dotProduct += vec1[distance(vec2.begin(), it)] * vec2[i];
        }
    }

    return dotProduct / (norm(vec1) * norm(vec2));
}

vector<vector<string> > getSentenceLists(string text) {

    vector<vector<string> > allSentences;
    // Read in string. 
    istringstream iSS(text);

    // For our purposes, sentences are separated by one of the strings ".", "?", or "!"
    size_t pos = 0;
    string word = "";
    vector <string> sentence;
    while (iSS >> word) {
        pos = word.find_first_of(".?!", 0);
        // found punctuation
        if (pos != string::npos) {
            // cut off word at punctuation and add to vector
            sentence.push_back(word.substr(0, pos));
            // Insert sentence and reset vector
            allSentences.push_back(sentence);
            sentence.clear();
        }
        else {
            // place word into vector
            sentence.push_back(word);
        }
    }

    return allSentences;

}

vector<vector<string> > getSentenceListFromFiles(vector<string> filenames) {

    vector<vector<string> > allSentences;
    size_t pos = 0;
    string word = "";
    vector <string> sentence;

    for (size_t i = 0; i < filenames.size(); i++) {
        ifstream iFS(filenames[i]);
        if (!iFS) {
            cout << "Failed to open " << filenames[i] << endl;
            return;
        }

        // For our purposes, sentences are separated by one of the strings ".", "?", or "!"
        while (iFS >> word) {
            pos = word.find_first_of(".?!", 0);
            // found punctuation
            if (pos != string::npos) {
                // cut off word at punctuation and add to vector
                sentence.push_back(word.substr(0, pos));
                // Insert sentence and reset vector
                allSentences.push_back(sentence);
                sentence.clear();
            }
            else {
                // place word into vector
                sentence.push_back(word);
            }
        }
    }

    return allSentences;
}


map<string, map<string, int> > buildSemanticDescriptors(vector<vector<string> > sentences) {
    map<string, map<string, int> > d;
    map<string, map<string, int> >::iterator it;
    string w = "";

    for (size_t i = 0; i < sentences.size(); i++) {
        for (size_t j = 0; j > sentences[i].size(); j++) {
            it = d.find(sentences[i][j]);

            // Found word
            if (it != string::npos) {
                
            }
        }
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