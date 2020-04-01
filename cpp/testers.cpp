#include "testers.h"
#include "synonyms.h"

void displaySentences(const vector<vector<string> >& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

void displaySemanticDescriptors(map<string, map<string, int> >& d) {
    const string LINE = "-----------------------------------------------------";
    string currKey = "";
    cout << LINE << "\n{ " << endl;
    for (map<string, map<string, int> >::iterator outIt = d.begin();
        outIt != d.end(); ++outIt) {

        cout << '\'' << outIt->first << "': {";
        for (map<string, int>::iterator inIt = d[outIt->first].begin();
            inIt != d[outIt->first].end(); ++inIt) {
            
            cout << '\'' << inIt->first << "': " << inIt->second << ", ";
        }
        cout << "}, " << endl;
    }
    cout << endl;
}

void testCosineSimilarity(const map<string, int>& mp) {
    double normal = -1;
    normal = norm(mp);
    cout << "Vector normal: " << normal << endl;
}