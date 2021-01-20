#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
    {
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, [](int a, int b) { return a < b; });
        cout << m / a[0] << endl;
    }
}