#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, d, u;
    while (cin >> n >> u >> d, n && u && d)
    {
        int res = 0;
        bool rest = false;
        while (n > 0)
        {
            if (rest)
            {
                n += d;
                rest = false;
                res++;
            }
            else
            {
                n -= u;
                rest = true;
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}