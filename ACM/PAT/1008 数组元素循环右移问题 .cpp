#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1005] = {0};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    m = n - m % n;
    for (int i = m; i < m + n - 1; i++)
        cout << a[i % n] << " ";
    cout << a[(m + n - 1) % n] << endl;

    return 0;
}