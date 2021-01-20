#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    int from, to;
} Node;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, res;
    while (cin >> n, n)
    {
        Node *node = new Node[n];
        for (int i = 0; i < n; i++)
            cin >> node[i].from >> node[i].to;
        sort(node, node + n, [](Node &a, Node &b) { return a.to < b.to; });
        res = 1;
        for (int j = 1, i = 0; j < n; j++)
            if (node[j].from >= node[i].to)
            {
                i = j;
                res++;
            }
        cout << res << endl;
        delete node;
    }
    return 0;
}