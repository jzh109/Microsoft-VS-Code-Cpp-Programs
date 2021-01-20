#include <bits/stdc++.h>
using namespace std;

void fun(int &res, int n)
{
    if (n == 1)
    {
        return;
    }
    res++;

    if (n & 1)
    {
        fun(res, (3 * n + 1) / 2);
    }
    else
    {
        fun(res, n / 2);
    }
}

int main()
{
    int res = 0;
    int n;
    cin >> n;
    fun(res, n);
    cout << res << endl;
    return 0;
}