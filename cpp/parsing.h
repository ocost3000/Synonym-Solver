#ifndef PARSING_H
#define PARSING_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> getFiles();

void toLowerCase(string& w);

int findInVec(const vector<int>& vec, const int& key);

int countInVec(const vector<int>& vec, const int& key);

void addToMap(map<string, int>& mp, const string& key);

void mergeMaps(map<string, int>& mp, map<string, int>& src, string key);

#endif