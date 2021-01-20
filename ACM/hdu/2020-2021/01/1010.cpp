#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct NODE
{
    ll w, s;
    bool operator<(const NODE &a) const
    {
        return w + s < a.w + a.s;
    }
} Node;

int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        ll res = 0;
        Node *node = new Node[n];
        for (int i = 0; i < n; i++)
            scanf("%lld%lld", &node[i].w, &node[i].s);
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        sort(node, node + n);
        for (int i = 1; i < n; i++)
        {
            res = max(res, node[i - 1].w - node[i].s);
            node[i].w += node[i - 1].w;
        }
        printf("%lld\n", res);
    }
    return 0;
}