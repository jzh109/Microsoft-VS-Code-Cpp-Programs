#include <cstdio>

int main()
{
    int t, n, temp;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            res += temp;
        }
        printf("%d\n", res);
        if (t != 0)
            printf("\n");
    }
}