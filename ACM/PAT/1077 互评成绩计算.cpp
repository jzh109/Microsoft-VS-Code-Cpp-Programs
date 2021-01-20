#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, cnt;
    cin >> n >> m;
    for (int u = 0; u < n; u++)
    {
        int t, a[105];
        cin >> t;
        cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int temp;
            cin >> temp;
            if (temp <= m && temp >= 0)
                a[cnt++] = temp;
        }
        sort(a, a + cnt);
        float g1 = 0;
        for (int i = 1; i < cnt - 1; i++)
            g1 += a[i];
        g1 /= (cnt - 2);
        g1 = (g1 + t) / 2;
        if ((g1 - (int)g1) < 0.5)
            cout << (int)g1 << endl;
        else
            cout << (int)g1 + 1 << endl;
    }
    return 0;
}
