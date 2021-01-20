#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, res = 1;
        cin >> n;
        while (n != 1)
        {
            if (n & 1)
            {
                res++;
                n -= 1;
            }
            else
                n >>= 1;
        }
        cout << res << endl;
    }
}