#ifndef TESTERS_H
#define TESTERS_H
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void displaySentences(const vector<vector<string> >& vec);

void displaySemanticDescriptors(map<string, map<string, int> >& d);

void testCosineSimilarity(const map<string, int>& mp);

#endif
