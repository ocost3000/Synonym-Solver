#ifndef SYNONYMS_H
#define SYNONYMS_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

double norm(vector<double> vec);

double cosineSimilarity(vector<double> vec1, vector<double> vec2);

vector<vector<string> > getSentenceLists(string text);

void getSentenceListFromFiles(vector<string> sentences);

map<string, map<string, int> > buildSemanticDescriptors(vector<string> sentences);

string mostSimilarWord(string word, vector<string> choices, map<string, int> semanticDescriptions);

double runSimilarityTest(string fileName, map<string, int> semanticDescriptions);


#endif