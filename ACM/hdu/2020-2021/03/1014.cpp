#include <bits/stdc++.h>
using namespace std;

inline int fun1(int n)
{
    return n * n * n;
}

inline int fun2(int n)
{
    return (n * (n + 1) * (n + 2)) / 6;
}

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int res = 0;
        for (int i = 0; fun1(i) <= n; i++)
        {
            for (int j = 0; fun1(i) + fun2(j) <= n; j++)
            {
                res = max(res, fun1(i) + fun2(j));
            }
        }
        cout << res << endl;
    }
    return 0;
}