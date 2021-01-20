#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            int a;
            cin >> a;
            cout << ((1 << a) - 1) << endl;
        }
    }
    return 0;
}