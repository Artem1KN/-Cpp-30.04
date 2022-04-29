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

    int n;
    fin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; ++i)
        fin >> v[i];

    int cur = v[0];
    int pr = v[0];
    int prpr = v[0];
    int ln = 0, maxl = 0;

    for (int i = 1; i < n; ++i)
    {
        prpr = pr;
        pr = cur;
        cur = v[i];
        if ( (pr > cur && pr > prpr) || (pr < cur && pr < prpr) ) ln++;
        else if (pr != cur) ln = 2;
        else ln = 1;
        maxl = max(maxl, ln);
    }
    fout << maxl;

	return 0;
}