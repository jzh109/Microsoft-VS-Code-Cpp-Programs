#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    while (cin >> n, n)
    {
        int res = 0, f = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp >= f)
            {
                res += (temp - f) * 6;
                res += 5;
                f = temp;
            }
            else if (temp < f)
            {
                res += (f - temp) * 4;
                res += 5;
                f = temp;
            }
        }
        cout << res << endl;
    }
}
