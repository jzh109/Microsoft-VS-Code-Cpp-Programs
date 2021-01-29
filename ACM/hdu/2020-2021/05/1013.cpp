#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        string s;
        bool a = false;
        bool b = false;
        bool c = false;
        bool d = false;
        getline(cin, s);
        if (s.length() < 8 || s.length() > 16)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (isupper(s[i]))
                a = true;
            else if (islower(s[i]))
                b = true;
            else if (isdigit(s[i]))
                c = true;
            else if (s[i] == '~' || s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^')
                d = true;
        }
        if (a + b + c + d >= 3)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}