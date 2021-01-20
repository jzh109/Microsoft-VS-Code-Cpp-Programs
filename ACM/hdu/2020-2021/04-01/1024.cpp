#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a, b;
    while (cin >> a >> b)
        cout << a * b / gcd(a, b) << endl;
}