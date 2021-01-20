#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        char c = s[0];
        int n = c - '0';
        for (int i = 0; i < n; i++)
            cout << i + 1;
        return 0;
    }
    else if (s.length() == 2)
    {
        char c = s[0];
        int n = c - '0';
        for (int i = 0; i < n; i++)
            cout << "S";
        c = s[1];
        n = c - '0';
        for (int i = 0; i < n; i++)
            cout << i + 1;
        return 0;
    }

    char c = s[0];
    int n = c - '0';
    for (int i = 0; i < n; i++)
        cout << "B";
    c = s[1];
    n = c - '0';
    for (int i = 0; i < n; i++)
        cout << "S";
    c = s[2];
    n = c - '0';
    for (int i = 0; i < n; i++)
        cout << i + 1;
    return 0;
}