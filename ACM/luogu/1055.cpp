#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    int a = 0, i = 1;
    getline(cin, s);
    for (int j = 0; j < 11; j++)
        if (isdigit(s[j]))
            a += (s[j] - '0') * (i++);
    a %= 11;
    if (a == s[12] - '0' || (a == 10 && s[12] == 'X'))
        cout << "Right" << endl;
    else
    {
        if (a == 10)
            cout << s.substr(0, 12) << "X" << endl;
        else
            cout << s.substr(0, 12) << a << endl;
    }

    return 0;
}