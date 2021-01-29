#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    string s;
    int n = 0;
} Node;

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Node *node = new Node[m];
        for (int i = 0; i < m; i++)
        {
            cin >> node[i].s;
        }
        for (int i = 0; i < m; i++)
        {
            string s = node[i].s;
            int temp = 0;
            for (int j = 0; j < n; j++)
                for (int k = j; k < n; k++)
                    if (s[j] > s[k])
                        temp++;
            node[i].n = temp;
        }
        sort(node, node + m, [](Node a, Node b) { return a.n < b.n; });
        for (int i = 0; i < m; i++)
        {
            cout << node[i].s << endl;
        }
    }
    return 0;
}