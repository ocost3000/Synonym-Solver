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

double norm(vector<int> vec);

double cosineSimilarity(vector<int> vec1, vector<int> vec2);

vector<vector<string> > getSentenceLists(string text);

vector<vector<string> > getSentenceListFromFiles(vector<string> filenames);

map<string, map<string, int> > buildSemanticDescriptors(vector<vector<string> > sentences);

string mostSimilarWord(string word, vector<string> choices, map<string, int> semanticDescriptions);

double runSimilarityTest(string fileName, map<string, int> semanticDescriptions);


#endif