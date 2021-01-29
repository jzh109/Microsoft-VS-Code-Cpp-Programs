#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
const int mod = 1e9 + 7;
int value[N], k, n, m, t;

struct Node
{
    char type[30];
    char name[30];
    int cost, val;
    bool operator<(const Node &b) const
    {
        if (strcmp(type, b.type) == 0)
            return val == b.val ? cost < b.cost : val > b.val; //质量相等返回价格低的
        return strcmp(type, b.type) < 0;
    }
} node[N];

vector<Node> v[N];
bool check(int mid)
{
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        int pos = mod;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].val >= mid)
                pos = min(pos, v[i][j].cost); //固定质量，每种类型娶价格最小
        }
        ans += pos;
        if (ans > m)
            return false;
    }
    return true;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        k = 0;
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
            scanf("%s %s %d %d", &node[i].type, &node[i].name, &node[i].cost, &node[i].val);
            value[i] = node[i].val;
        }
        sort(value, value + n);
        sort(node, node + n);
        for (int i = 0; i + 1 < n; i++)
        {
            while (i + 1 < n && strcmp(node[i].type, node[i + 1].type) == 0)
            {
                v[k].push_back(node[i]);
                i++;
            }
            v[k].push_back(node[i]);
            k++;
        }
        int l = 0, r = n - 1;
        int mid = (r + l) >> 1;
        while (l <= r)
        {
            if (check(value[mid]))
                l = mid + 1;
            else
                r = mid - 1;
            mid = (l + r) >> 1;
        }
        printf("%d\n", value[mid]);
    }
    return 0;
}