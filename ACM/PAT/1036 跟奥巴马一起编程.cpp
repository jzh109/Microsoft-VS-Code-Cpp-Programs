#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int row, col;
    char c;
    cin >> col >> c;
    if (col & 1)
        row = col >> 1 + 1;
    else
        row = col >> 1;
    for (int i = 0; i < col; i++)
        cout << c;
    cout << endl;
    for (int i = 0; i < (row == 1 ? 1 : row - 2); i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == 0 || j == col - 1)
                cout << c;
            else
                cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < col; i++)
        cout << c;
    cout << endl;
    return 0;
}
