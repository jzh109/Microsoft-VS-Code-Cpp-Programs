#include <bits/stdc++.h>
using namespace std;

struct Node
{
    double a, b;
    double v;
    bool operator<(Node &o) const
    {
        return v > o.v;
    }
} node[1005];

int main()
{
    int m, n;
    while (cin >> m >> n, m != -1 && n != -1)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> node[i].a >> node[i].b;
            node[i].v = node[i].a / node[i].b;
        }
        sort(node, node + n);
        double res = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (m < node[i].b)
            {
                res += (m * node[i].v);
                break;
            }
            else
            {
                res += node[i].a;
                m -= node[i].b;
            }
        }
        printf("%.3lf\n", res);
    }
    return 0;
}