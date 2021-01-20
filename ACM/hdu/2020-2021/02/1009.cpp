#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long n, a[10005], t;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n == 1)
        {
            cout << a[1] << endl;
            continue;
        }
        ans = a[1] / gcd(a[1], a[2]) * a[2];
        for (int i = 3; i <= n; i++)
            ans = ans / gcd(ans, a[i]) * a[i];
        cout << ans << endl;
    }
    return 0;
}
