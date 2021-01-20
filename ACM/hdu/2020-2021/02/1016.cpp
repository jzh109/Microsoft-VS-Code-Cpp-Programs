#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n, n)
    {
        int a = 0;
        while (!(n & 1))
        {
            n >>= 1;
            a++;
        }
        cout << (1 << a) << endl;
    }
    return 0;
}