#include <stdio.h>

typedef long long ll;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll x, y, n, temp;
        scanf("%lld%lld%lld", &x, &y, &n);
        temp = (n - y) / x;
        printf("%lld\n", temp * x + y);
    }
    return 0;
}