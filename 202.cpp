#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");

	string str, sub;
	fin >> str;
	fin >> sub;

	vector <int> ans;

	for (int i = 0; i <= str.size() - sub.size(); i++) {
		if (str.substr(i, sub.size()) == sub) {
			ans.push_back(i);
		}
	}
	for (auto now : ans) {
		fout << now << " ";
	}

	return 0;
}