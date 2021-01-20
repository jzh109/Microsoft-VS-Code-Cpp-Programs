#include <bits/stdc++.h>
using namespace std;

int t, n, x, t_max;
long long sum;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        sum = t_max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            t_max = max(t_max, x);
            sum += x;
        }
        sum -= t_max;
        if (sum >= t_max - 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}