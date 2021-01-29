#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    int from, to;
    bool operator<(const NODE &a) const
    {
        if (from != a.from)
            return from < a.from;
        return to < a.to;
    }
} Node;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int m, n, res = 0;
    cin >> m >> n;
    Node *node = new Node[n];

    for (int i = 0; i < n; i++)
    {
        cin >> node[i].from >> node[i].to;
    }

    sort(node, node + n);

    for (int i = 0; i < n - 1; i++)
    {
        if (node[i].to >= node[i + 1].from)
        {
            node[i].to = max(node[i + 1].to, node[i].to);
            for (int j = i + 1; j < n - 1; j++)
            {
                node[j] = node[j + 1];
            }
            // node[i + 1] = node[n - 1];
            n--;
            i--;
            // sort(node, node + n);
        }
    }

    for (int i = 0; i < n; i++)
    {
        res += node[i].to - node[i].from + 1;
    }

    // bool *have = new bool[m + 1];
    // for (int i = 0; i < n; i++)
    // {
    //     int from, to;
    //     cin >> from >> to;
    //     for (int j = from; j <= to; j++)
    //     {
    //         have[j] = true;
    //     }
    // }
    // for (int i = 0; i <= m; i++)
    // {
    //     if (!have[i])
    //         res++;
    // }

    cout << m + 1 - res << endl;
    return 0;
}