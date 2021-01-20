#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a, b;
} s[100005];
int r[100005];

bool cmp1(const node &a, const node &b)
{
    return a.a < b.a;
}

int main()
{
    int t, n, ans, cas;
    scanf("%d", &t);
    for (cas = 1; cas <= t; cas++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &s[i].a, &s[i].b);
        if (n == 1)
        {
            printf("Case 1: %d\n", min(s[0].a, s[0].b));
            continue;
        }
        sort(s, s + n, cmp1);
        memset(r, 0, sizeof(r));
        for (int i = n; i >= 0; i--)
        {
            r[i] = max(r[i + 1], s[i].b);
        }
        ans = min(0x3F3F3F3F, s[0].a + r[1]);
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, s[i].a + r[i + 1]);
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}