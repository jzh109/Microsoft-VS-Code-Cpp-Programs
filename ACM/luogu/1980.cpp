#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, x, res = 0;
    cin >> n >> x;
    x += 48;
    for (int i = 1; i < n + 1; i++)
    {
        stringstream ss;
        ss << i;
        string s = ss.str();
        for (char c : s)
            if (c == x)
                res++;
    }
    cout << res << endl;
    return 0;
}