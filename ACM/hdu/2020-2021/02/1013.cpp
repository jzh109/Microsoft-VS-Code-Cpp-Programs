#include <stdio.h>

long long fastPower(long long base, long long power)
{
    int res = 1;
    while (power)
    {
        if (power & 1)
            res = res * base % 100;
        power >>= 1;
        base = (base * base) % 100;
    }
    return res;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        long long a;
        scanf("%ld", &a);
        long long res = fastPower(a, a);
        printf("%d\n", res % 10);
    }
    return 0;
}