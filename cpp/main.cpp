#include "synonyms.h"
#include "parsing.h"

// Testing Functions
void displaySentences(vector<vector<string> > vec);
void displaySemanticDescriptors(map<string, map<string, int> >& d);

int main() {

    // TESTING getSentenceListFromFiles
    vector<string> files = getFiles();
    vector<vector<string> > sentenceList; 
    sentenceList = getSentenceListFromFiles(files);
    map<string, map<string, int> > theMap;
    theMap = buildSemanticDescriptors(sentenceList);
    displaySemanticDescriptors(theMap);

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

void displaySemanticDescriptors(map<string, map<string, int> >& d) {
    string currKey = "";
    for (map<string, map<string, int> >::iterator outIt = d.begin();
        outIt != d.end(); ++outIt) {

        currKey = outIt->first;
        cout << currKey << " | ";

        for (map<string, int>::iterator inIt = d[currKey].begin();
            inIt != d[currKey].end(); ++inIt) {

            cout << '"' << inIt->first << "\": " << inIt->second << ", ";
        }
        cout << endl;
    }
}