#include <iostream>
using namespace std;

typedef long long ll;
inline int solve(ll n)
{
    if (n == 1)
        return 0;
    if (n % 3 != 0)
        return -1;
    int res = 0;
    while (n != 1)
    {
        res++;
        if (n % 3 != 0)
            return -1;
        if (n % 6 == 0)
            n /= 6;
        else
            n <<= 1;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}