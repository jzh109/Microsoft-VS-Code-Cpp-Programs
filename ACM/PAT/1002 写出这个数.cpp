#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> m;
    m.insert(pair<int, string>(0, "ling"));
    m.insert(pair<int, string>(1, "yi"));
    m.insert(pair<int, string>(2, "er"));
    m.insert(pair<int, string>(3, "san"));
    m.insert(pair<int, string>(4, "si"));
    m.insert(pair<int, string>(5, "wu"));
    m.insert(pair<int, string>(6, "liu"));
    m.insert(pair<int, string>(7, "qi"));
    m.insert(pair<int, string>(8, "ba"));
    m.insert(pair<int, string>(9, "jiu"));
    string str;
    int sum = 0;
    cin >> str;
    for (long long unsigned int i = 0; i < str.length(); i++)
    {
        sum += str[i] - '0';
    }
    str.clear();
    stringstream ss;
    for (int i = 0; sum != 0; i++)
    {
        ss << sum - (sum / 10) * 10;
        sum /= 10;
    }
    ss << "\0";
    str = ss.str();
    for (int i = str.length() - 1; i >= 0; i--)
    {
        string s = m.find(str[i] - '0')->second;
        if (i == 0)
            cout << s;
        else
            cout << s << " ";
    }
    cout << endl;
    return 0;
}