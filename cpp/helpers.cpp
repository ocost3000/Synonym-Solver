#include "helpers.h"

vector<string> getFiles() {
    // Will read in book files from book-names.txt
    // You MUST put each file on a new line< otherwise getline won't do its job
    vector<string> strVec;
    ifstream iFS("/home/ocost6/synonymSolver/cpp/book-names.txt");
    if (!iFS) {
        cout << "error getting books, please check getFiles() in parsing.cpp"
            << endl;
        return strVec;
    }
    string bookName = "";
    while (iFS >> bookName) {
        strVec.push_back(bookName);
    }
    iFS.close();
    return strVec;
}

void toLowerCase(string& w) {
    for (size_t i = 0; i < w.length(); i++) {
        w[i] = tolower(w[i]);
    }
}

int countInVec(const vector<int>& vec, const int& key) {
    // Default value will be returned if key not found in vec
    int count = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == key) {
            count++;
        }
    }
    return count;
}

void addToMap(map<string, int>& mp, const string& key) {
    if (mp.count(key)) {
        mp[key]++;
    }
    else {
        mp.emplace(key, 1);
    }
}

void mergeMaps(map<string, int>& mp, map<string, int>& src, string key) {
    for (map<string, int>::iterator it = src.begin(); it != src.end(); ++it) {
        if (mp.count(it->first)) {
            mp[it->first] += src[it->first];
        }
        else {
            mp.emplace(it->first, src[it->first]);
        }
    }
}