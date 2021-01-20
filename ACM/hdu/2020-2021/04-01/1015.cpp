#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll m, n;
    while (cin >> m >> n)
    {
        ll *a = new ll[n], sum = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum < m)
        {
            cout << "impossible" << endl;
            continue;
        }
        sort(a, a + n, [](ll a, ll b) { return a > b; });
        for (int i = 0; i < n; i++)
        {
            m -= a[i];
            res++;
            if (m <= 0)
                break;
        }
        cout << res << endl;
    }
}