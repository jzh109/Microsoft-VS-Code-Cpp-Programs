#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s, a;
    int res = 0, f;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    getline(cin, a);
    a += "   ";
    for (int i = 0; i < a.length(); i++)
        a[i] = tolower(a[i]);
    for (int i = 0; i < a.length() - 1; i++)
        for (int j = i; j < a.length(); j++)
            if (!isalpha(a[j]))
            {
                if (a.substr(i, j - i) == s)
                {
                    res++;
                    if (res == 1)
                        f = i;
                }
                i = j;
                break;
            }
    if (res == 0)
        cout << "-1" << endl;
    else
        cout << res << " " << f << endl;
    return 0;
}