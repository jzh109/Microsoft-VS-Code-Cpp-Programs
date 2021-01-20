#include <iostream>
#include <cstdio>
using namespace std;
#define M 2010

int pre[M * 2];

int Find(int x)
{
    int r = x;
    if(r != pre[r])
        return pre[r] = Find(pre[r]);
    return r;
}

void mix(int a, int b)
{
    int x = Find(a);
    int y = Find(b);
    if(x != y)
        pre[x] = y;
}

int main()
{
    int t, n, m, x, y, cas = 1, flag;
    scanf("%d", &t);
    while(t--)
    {
        flag = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n*2; i++)
            pre[i] = i;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            if(Find(x) == Find(y))
            {
                flag = 1;
            }
            else
            {
                mix(x, y + n);
                mix(x + n, y);
            }
        }
        printf("Scenario #%d:\n", cas++);
        if(flag == 1)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
