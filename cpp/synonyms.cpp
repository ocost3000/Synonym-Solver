#include "synonyms.h"

// TODO find out what cpp equivalent is of vec
double norm(vector<double> vec) {
    /*
    Return the norm of a vector stored as a dictionary,
    as described in the instructions.
    */

    double sumOfSquares = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        sumOfSquares += vec[i] * vec[i];
    }

    return sqrt(sumOfSquares);
}

// TODO find out what cpp equivalent is of vec

double cosineSimilarity(vector<double> vec1, vector<double> vec2) {
    /*
    Return the cosine similarity of sparse vectors vec1 and vec2,
    stored as dictionaries as described in the handout for Project 2.
    */

    double dotProduct = 0.0; // floating point to handle large numbers
    for (size_t i = 0; i < vec1.size(); i++) {
        vector<double>::iterator it = find(vec2.begin(), vec2.end(), vec1[i]);
        if (it != vec2.end()) {     // TODO if vec1[i] in vec2 
            dotProduct += vec1[distance(vec2.begin(), it)] * vec2[i];
        }
    }

    return dotProduct / (norm(vec1) * norm(vec2));
}

vector<vector<string> > getSentenceLists(string text) {

    vector< vector <string> > allSentences;
    // Read in book. 
    ifstream iFS(text);
    if (!iFS) {
        cout << "Error opening file: " + text << endl;
    }

    // For our purposes, sentences are separated by one of the strings ".", "?", or "!"
    size_t pos = 0;
    string word = "";
    vector <string> sentence;
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

    return allSentences;

}

/*
void getSentenceListFromFiles(vector<string> sentences) {

}

map<string, map<string, int> > buildSemanticDescriptors(vector<string> sentences);
    Map d;

    return d;
}

string mostSimilarWord(string word, vector<string> choices, map<string, int> semanticDescriptions);

    return wordMostSimilar;
}

double runSimilarityTest(string fileName, map<string, int> semanticDescriptions) {

    return accuracy;
}
*/