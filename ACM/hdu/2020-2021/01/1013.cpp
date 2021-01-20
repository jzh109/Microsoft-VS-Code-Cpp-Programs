#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    int t, a[205];
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n, from, to;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> from >> to;
            if (from > to)
                swap(from, to);
            for (int j = (from + 1) / 2; j <= (to + 1) / 2; j++)
                a[j]++;
        }
        sort(a, a + 201, cmp);
        cout << (a[0] * 10) << endl;
    }
    return 0;
}