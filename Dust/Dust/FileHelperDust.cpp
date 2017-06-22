#include "FileHelperDust.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "Debug.h"

vector<string> GetTokens(string str, char delimiter)
{
	vector<string> r;
	istringstream ss(str);
	string token;

	while (getline(ss, token, delimiter))
		r.push_back(token);

	return r;
}

vector<string> ReadFile(string path)
{
	vector<string> r;
	string line;
	std::ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			r.push_back(line);
		}
		file.close();
		return r;
	}

	Debug::Warning("Cannot Open: " + path);
	
	return r;
}

vector<string> GetTokensFromFile(string path, char delimiter)
{
	vector<string> r;
	vector<string> tokens;
	vector<string> lines = ReadFile(path);
	for (unsigned int i = 0; i < lines.size(); ++i)
	{
		tokens = GetTokens(lines[i], delimiter);
		r.insert(r.end(), tokens.begin(), tokens.end());
	}
	return r;
}

wstring stows(string str)
{
	wstring r = wstring(str.length(), L' ');
	std::copy(str.begin(), str.end(), r.begin());
	return r;
}

string wstos(wstring str)
{
	string r = string(str.length(), ' ');
	std::copy(str.begin(), str.end(), r.begin());
	return r;
}