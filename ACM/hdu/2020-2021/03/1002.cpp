#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
int a[2000], n;
long long num;
void dfs(long long t)
{
    int i = 1;
    double v = sqrt(t + a[i]);
    while (v - (int)v != 0 && a[i] != 0)
    {
        i++;
        v = sqrt(t + a[i]);
    }
    if (i > n)
        return;
    a[i] = t;
    num = max(num, t);
    dfs(t + 1);
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        num = 0;
        dfs(1);
        num ? printf("%lld\n", num) : printf("-1\n");
    }
}