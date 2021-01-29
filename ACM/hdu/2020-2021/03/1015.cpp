#include <bits/stdc++.h>
using namespace std;

bool prime(long long a)
{
    long long sq = sqrt(a);
    for (int i = 2; i <= sq; i++)
        if (a % i == 0)
            return false;
    return true;
}

bool fastPower(long long a, long long p)
{
    long long res = 1, mod = p, c = a;
    while (p)
    {
        if (p & 1)
            res = res * a % mod;
        p >>= 1;
        a = (a * a) % mod;
    }
    if (res == c)
        return true;
    return false;
}

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int a, q;
    while (cin >> q >> a)
    {
        if (a == 0 && q == 0)
            break;
        if (!prime(q) && fastPower(a, q))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}