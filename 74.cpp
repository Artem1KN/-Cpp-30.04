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

    int n, m;
    fin >> n >> m;
    if (m == 1)
    {
        fout << n;
        return 0;
    }
    int s = 0;
    while (m % 2 != 0)
    {
        s += n / 2;
        n -= n / 2;
        m = (m + 1) / 2;
    }
    s += m / 2;
    fout << s;

	return 0;
}