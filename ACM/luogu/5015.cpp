#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    int res = 0;
    while (cin >> s)
    {
        res += s.length();
    }
    cout << res << endl;
    return 0;
}