#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, cnt = 0, res = 0;
    int a[15] = {0};
    int b[105] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            b[cnt++] = 10 * a[i] + a[j];
            b[cnt++] = 10 * a[j] + a[i];
        }
    for (int i = 0; i < cnt; i++)
        res += b[i];
    cout << res << endl;
    return 0;
}
