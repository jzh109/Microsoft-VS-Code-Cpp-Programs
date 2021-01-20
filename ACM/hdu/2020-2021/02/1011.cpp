#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    int ans = 1;
    while (n != 1)
    {
        n = n & 1 ? 3 * n + 1 : n / 2;
        ans++;
    }
    return ans;
}
int findmax(int from, int to)
{
    int ans = 0;
    for (int n = from; n <= to; n++)
    {
        ans = max(ans, count(n));
    }
    return ans;
}
int main()
{
    int a, b;
    while (cin >> a >> b)
        printf("%d %d %d\n", a, b, findmax(min(a, b), max(a, b)));
    return 0;
}