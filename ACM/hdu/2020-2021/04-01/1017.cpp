#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    int from, to;
    int prev = 0, val = 1;
    int opt = val;
} Node;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n, n)
    {
        Node *node = new Node[n + 1];
        int res = 0;
        for (int i = 1; i <= n; i++)
            cin >> node[i].from >> node[i].to;
        sort(node + 1, node + n + 1, [](Node &a, Node &b) { return a.to < b.to; });
        // node[0].val = 0;
        node[0].opt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = n; j > 0; j--)
                if (node[j].to <= node[i].from)
                {
                    node[i].prev = j;
                    break;
                }
        for (int i = 1; i <= n; i++)
            node[i].opt = max(node[i - 1].opt, node[i].val + node[node[i].prev].opt);
        for (int i = 1; i <= n; i++)
            res = max(res, node[i].opt);
        cout << res << endl;
        delete node;
    }
}