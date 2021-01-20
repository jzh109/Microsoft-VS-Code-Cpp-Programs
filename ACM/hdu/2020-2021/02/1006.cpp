#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m;
    while (cin >> n >> m, n && m)
    {
        double d = sqrt(n * n - 4 * m);
        if (d >= 0 && d - (int)(d) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}