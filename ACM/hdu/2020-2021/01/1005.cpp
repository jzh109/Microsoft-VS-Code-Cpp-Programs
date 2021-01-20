#include <bits/stdc++.h>
using namespace std;

int a[20005];

bool cmp(const int a, const int b)
{
    return a > b;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--)
    {
        int res = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n < 3)
        {
            cout << "0" << endl;
            continue;
        }
        sort(a, a + n, cmp);
        for (int i = 2; i < n; i += 3)
            res += a[i];
        cout << res << endl;
    }
}