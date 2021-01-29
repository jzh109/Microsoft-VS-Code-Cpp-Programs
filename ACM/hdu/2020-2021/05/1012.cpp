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
        //getchar();
        getline(cin, s);

        map<char, int> m;
        m['a'] = 0;
        m['e'] = 0;
        m['i'] = 0;
        m['o'] = 0;
        m['u'] = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                m[s[i]]++;
        }
        cout << "a:" << m['a'] << endl;
        cout << "e:" << m['e'] << endl;
        cout << "i:" << m['i'] << endl;
        cout << "o:" << m['o'] << endl;
        cout << "u:" << m['u'] << endl;
        if (t)
            cout << endl;
    }
    return 0;
}