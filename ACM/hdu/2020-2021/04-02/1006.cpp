#include <cstdio>

int main()
{
    int n, temp;
    while (~scanf("%d", &n))
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            res += temp;
        }
        printf("%d\n", res);
    }
}