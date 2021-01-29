#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    bool p = true;
    cin >> n;
    if (n < 0)
        p = false;
    n = abs(n);
    stringstream ss;
    ss << n;
    string s = ss.str();
    reverse(s.begin(), s.end());
    n = stoi(s);
    if (!p)
        cout << "-";
    cout << n << endl;
    return 0;
}