#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    int m, n, l = 1;

    while (cin >> m >> n, m && n)
    {
        int a[55] = {0};
        int b[1005] = {0};
        int c[1005] = {0};
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            c[a[i]] = 1;
        }
        for (int i = m * n; i >= 0 && k <= n; i--)
        {
            if (c[i])
                continue;
            b[k++] = i;
        }
        sort(a, a + n, cmp);
        sort(b, b + n, cmp);
        int res = 0;
        k = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[k])
            {
                res++;
                k++;
            }
        }
        cout << "Case " << l++ << ": " << n - res << endl;
    }
}