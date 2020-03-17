#include "synonyms.h"
#include "parsing.h"

// Test functions
void displaySentences(vector<vector<string> > vec);

int main() {

    // TESTING getSentenceListFromFiles
    vector<string> files = {"/home/ocost6/synonymSolver/books/test-hows-it-going.txt"};
    vector<vector<string> > sentenceList; 
    sentenceList = getSentenceListFromFiles(files);
    displaySentences(sentenceList);

   // PARSING OKAY
}

void displaySentences(vector<vector<string> > vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}