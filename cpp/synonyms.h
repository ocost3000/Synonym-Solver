#ifndef SYNONYMS_H
#define SYNONYMS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

double norm(const vector<int>& vec);

double cosineSimilarity(const vector<int>& vec1, const vector<int>& vec2);

vector<vector<string> > getSentenceLists(stringstream& ss);

vector<vector<string> > getSentenceListFromFiles(
                                                const vector<string>& filenames
                                                );

map<string, map<string, int> > buildSemanticDescriptors(
                                        vector<vector<string> >& sentences
                                        );

string mostSimilarWord(string word, vector<string> choices, map<string, int> semanticDescriptions);

double runSimilarityTest(string fileName, map<string, int> semanticDescriptions);

#endif