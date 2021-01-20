#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n)
    {
        float up = 0, down = 0;
        for (int i = 0; i < n; i++)
        {
            float a, b;
            cin >> a >> b;
            if (b != -1)
            {
                b = b >= 90 ? 4.0 : (b >= 80 ? 3.0 : (b >= 70 ? 2.0 : (b >= 60 ? 1.0 : 0.0)));
                up += a * b;
                down += a;
            }
        }

        if (down != 0)
            printf("%.2f\n", up / down);
        else
            cout << -1 << endl;
    }
    return 0;
}