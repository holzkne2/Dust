#include "FileHelperDust.h"
#include <sstream>
#include <fstream>
#include <iostream>

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

	cout << "Cannot Open: " << path << endl;
	
	return r;
}