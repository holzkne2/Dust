#pragma once
#include "boost\filesystem.hpp"
#include <vector>
#include <string>

using namespace boost::filesystem;
using namespace std;

vector<string> GetTokens(string str, char delimiter);

vector<string> ReadFile(string path);

vector<string> GetTokensFromFile(string path);

wstring stows(string str);

string wstos(wstring str);