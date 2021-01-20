#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    int p, m;
    bool operator<(const NODE &a) const
    {
        return p > a.p;
    }
} Node;

int main(void)
{
    int v, n;
    while (scanf("%d", &v), v)
    {
        int res = 0;
        scanf("%d", &n);
        Node *node = new Node[n];
        for (int i = 0; i < n; i++)
            scanf("%d%d", &node[i].p, &node[i].m);
        sort(node, node + n);
        for (int i = 0; i < n; i++)
        {
            if (v >= node[i].m)
            {
                res += node[i].p * node[i].m;
                v -= node[i].m;
            }
            else
            {
                res += node[i].p * v;
                break;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}