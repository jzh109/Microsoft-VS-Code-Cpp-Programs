#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<char, int> &a, const pair<char, int> &b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    string s;
    getline(cin, s);
    map<char, int> m;
    m.clear();
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (isalpha(s[i]))
            m[tolower(s[i])]++;
    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first << " " << v[0].second << endl;
    return 0;
}