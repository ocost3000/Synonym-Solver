#include "synonyms.h"
#include "helpers.h"
#include "testers.h"
#include <chrono>

// Testing Functions
void displaySentences(vector<vector<string> > vec);
void displaySemanticDescriptors(map<string, map<string, int> >& d);

int main() {

    auto start = chrono::high_resolution_clock::now();

    vector<string> files = getFiles();
    vector<vector<string> > sentenceList; 
    sentenceList = getSentenceListFromFiles(files);
    map<string, map<string, int> > theMap;
    theMap = buildSemanticDescriptors(sentenceList);
    double accuracy = runSimilarityTest(
                            "/home/ocost6/synonymSolver/cpp/test.txt", theMap);
    cout << accuracy << endl;

    // Measure runtime
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double, milli>(stop - start).count(); 
    cout << "\nRuntime: " << duration << " ms" << endl;

    return 0;
}
