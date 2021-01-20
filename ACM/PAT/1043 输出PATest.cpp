#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    map<char, int> m;
    m.clear();
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't')
            m[str[i]]++;
    }
    while (!m.empty())
    {
        if (m.count('P'))
        {
            cout << "P";
            m['P']--;
            if (m['P'] == 0)
                m.erase('P');
        }
        if (m.count('A'))
        {
            cout << "A";
            m['A']--;
            if (m['A'] == 0)
                m.erase('A');
        }
        if (m.count('T'))
        {
            cout << "T";
            m['T']--;
            if (m['T'] == 0)
                m.erase('T');
        }
        if (m.count('e'))
        {
            cout << "e";
            m['e']--;
            if (m['e'] == 0)
                m.erase('e');
        }
        if (m.count('s'))
        {
            cout << "s";
            m['s']--;
            if (m['s'] == 0)
                m.erase('s');
        }
        if (m.count('t'))
        {
            cout << "t";
            m['t']--;
            if (m['t'] == 0)
                m.erase('t');
        }
    }
    return 0;
}