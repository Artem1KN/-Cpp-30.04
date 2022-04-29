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

    int n;
    fin >> n;

    int nbr = 0;
    int** arr = new int* [n];

    for (int i = 0; i < n; ++i)
        arr[i] = new int[n];

    int sp;
    if (n % 2 == 0)
        sp = n / 2;
    else
        sp = n / 2 + 1;

    for (int i = 0; i < sp; i++)
    {
        for (int j = i; j < n - i; j++)
            arr[i][j] = ++nbr;

        for (int j = i + 1; j < n - i; j++)
            arr[j][n - i - 1] = ++nbr;

        for (int j = i + 1; j < n - i; j++)
            arr[n - i - 1][n - j - 1] = ++nbr;

        for (int j = i + 1; j < n - i - 1; j++)
            arr[n - j - 1][i] = ++nbr;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fout << arr[i][j] << " ";
        fout << endl;
    }

    return 0;
}