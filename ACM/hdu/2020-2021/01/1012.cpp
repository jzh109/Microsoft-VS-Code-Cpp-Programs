#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct NODE
{
    ll a, b;
    bool operator<(const NODE &other) const
    {
        return a * other.b < b * other.a;
    }
} Node;

int main(void)
{
    int n;
    const ll mod = 365ll * 24ll * 60ll * 60ll;
    while (scanf("%d", &n), n)
    {
        Node *node = new Node[n];
        for (int i = 0; i < n; i++)
            scanf("%lld%lld", &node[i].a, &node[i].b);
        sort(node, node + n);
        ll res = 0;
        res += node[0].a;
        for (int i = 1; i < n; i++)
            res += (node[i].a + node[i].b * res) % mod;
        printf("%lld\n", res % mod);
    }
    return 0;
}