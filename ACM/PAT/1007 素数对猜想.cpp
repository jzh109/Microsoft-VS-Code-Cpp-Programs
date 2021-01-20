#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

bool prime(int a)
{
    if (a == 1)
        return false;
    int max = sqrt(a) + 1;
    for (int i = 2; i <= max; i++)
        if (abs((a / i) * i - a) < eps)
            return false;
    return true;
}

int main()
{
    int n, res = 0;
    cin >> n;
    for (int i = 3; i <= n; i += 2)
        if (prime(i - 2) && prime(i))
            res++;
    cout << res << endl;

    // for (int i = 3; i < 1000; i += 2)
    // {
    //     if (prime(i))
    //         cout << i << " ";
    // }
    return 0;
}