#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    long long val;
    long long opt;
} Node;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        Node *node = new Node[n + 1];
        long long res = 0;
        node[0].opt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> node[i].val;
            node[i].opt = node[i].val;
        }
        for (int i = 1; i <= n; i++)
        {
            sort(node + 1, node + i, [](Node &a, Node &b) { return a.opt < b.opt; });
            for (int j = i - 1; j >= 0; j--)
                if (node[j].val < node[i].val)
                {
                    node[i].opt += node[j].opt;
                    break;
                }
        }
        for (int i = 1; i <= n; i++)
            res = max(res, node[i].opt);
        cout << res << endl;
    }
}