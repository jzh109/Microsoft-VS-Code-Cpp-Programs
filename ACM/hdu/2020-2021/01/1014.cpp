#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    int w, l;
    bool operator<(const NODE &a) const
    {
        return w == a.w ? l < a.l : w < a.w;
    }
} Node;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Node node[n];
        int res = 0, l[n], w[n], j;
        for (int i = 0; i < n; i++)
            cin >> node[i].l >> node[i].w;
        sort(node, node + n);
        for (int i = 0; i < n; i++)
        {
            l[res] = node[i].l;
            w[res] = node[i].w;
            for (j = 0; j < res; j++)
            {
                if (l[j] <= l[res] && w[j] <= w[res])
                {
                    l[j] = l[res];
                    w[j] = w[res];
                    break;
                }
            }
            if (j == res)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
