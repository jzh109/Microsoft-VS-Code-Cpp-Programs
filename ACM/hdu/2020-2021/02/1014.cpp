#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, i, k;
    while (~scanf("%d", &k))
    {
        for (i = 1; i <= 65; i++)
        {
            if ((18 + i * k) % 65 == 0)
            {
                printf("%d\n", i);
                break;
            }
        }
        if (i >= 66)
            printf("no\n");
    }
    return 0;
}