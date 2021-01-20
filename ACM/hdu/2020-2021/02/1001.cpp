#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
    long long a, b;
    while (cin >> a >> b)
        cout << a * b / gcd(a, b) << endl;
    return 0;
}