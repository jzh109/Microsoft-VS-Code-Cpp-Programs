#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v;
    v.clear();
    string str;
    while (cin >> str)
        v.push_back(str);
    for (int i = v.size() - 1; i > 0; i--)
        cout << v[i] << " ";
    cout << v[0] << endl;
    return 0;
}