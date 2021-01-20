#include <bits/stdc++.h>
using namespace std;

void print(bool **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
}

void process(bool **a, int n, int t)
{
    for (int i = 0; i < n; i++)
    {
        if (i != t)
            a[t][i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        a[i][t] = false;
    }
}
int res(bool **a, int n)
{
    int result = -1, min = 0x3F3F3F3F;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (!a[i][j])
            {
                temp <<= 1;
            }
            else
            {
                temp += 1;
                temp <<= 1;
            }
        }
        if (min > temp)
        {
            min = temp;
            result = i;
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    int n = -1;
    string s;
    cout << "Input number of pages:";
    cin >> n;
    cout << "Input array CPU read pages:";
    cin >> s;
    int len = s.length();
    bool **a = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new bool[n];
        memset(a[i], false, n);
    }
    for (int i = 0; i < len; i++)
    {
        int t = s[i] - 48;
        process(a, n, t);
        print(a, n);
    }
    // print(a, n);
    cout << "LRU page is PAGE " << res(a, n) << endl;
}