#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int a[2005] = {0};
    cin >> t;
    int x = 0;
    for (int i = 0; i < 66; i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            x = 3 * i + 4 * j;
            a[x] = 1;
            if (x > 200)
            {
                x = 0;
                break;
            }
        }
    }
    while (t--)
    {
        int n;
        cin >> n;
        int y = n;
        n = n / 50;
        for (; a[n] != 1; n--)
            continue;
        cout << y - 50 * n << endl;
    }
    return 0;
}