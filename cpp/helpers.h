#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> getFiles();

void toLowerCase(string& w);

int countInVec(const vector<int>& vec, const int& key);

void addToMap(map<string, int>& mp, const string& key);

void mergeMaps(map<string, int>& mp, map<string, int>& src, string key);

#endif