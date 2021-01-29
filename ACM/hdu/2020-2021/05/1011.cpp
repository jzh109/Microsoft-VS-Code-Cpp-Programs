#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    while (getline(cin, s), s != "")
    {
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ')
                s[i + 1] = toupper(s[i + 1]);
        s[0] = toupper(s[0]);
        cout << s << endl;
    }
    return 0;
}