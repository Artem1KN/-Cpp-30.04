#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

	int k, m;
	fin >> k >> m;

	vector <pair <int, int>> s;
	for (int i = 0; i < m; i++) {
		pair <int, int> p;
		fin >> p.second >> p.first;
		s.push_back(p);
	}
	sort(s.begin(), s.end());
	for (int i = m - 1; i >= 0; i--) {
		if (s[i].second + 1 == k) {
			k = s[i].second;
		}
		else if (s[i].second == k) {
			k = s[i].second + 1;
		}
	}

	fout << k;

	return 0;
}