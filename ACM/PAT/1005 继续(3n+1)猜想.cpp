#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[105][2] = {{0}}, b[105] = {0}, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i][0];
    for (int k = 0; k < n; k++)
    {
        int temp = a[k][0];
        while (temp != 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i][0] == temp)
                {
                    a[i][1]++;
                    break;
                }
            }
            if (temp & 1)
                temp = (temp * 3 + 1) / 2;
            else
                temp >>= 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i][1] == 1)
            b[res++] = a[i][0];
    if (res > 0)
    {
        sort(b, b + res, [](int a, int b) { return a > b; });
        for (int i = 0; i < res - 1; i++)
            cout << b[i] << " ";
        cout << b[res - 1] << endl;
    }
    else
        cout << "0" << endl;

    return 0;
}