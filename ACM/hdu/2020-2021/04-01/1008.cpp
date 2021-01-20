#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef struct NODE
{
    int a;
    bool pos;
    bool operator<(const NODE &s) const
    {
        return a > s.a;
    }
} Node;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n, n)
    {
        Node *node = new Node[n];
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp < 0)
                node[i].pos = false;
            else
                node[i].pos = true;
            node[i].a = fabs(temp);
        }
        sort(node, node + n);
        for (int i = 0; i < n - 1; i++)
        {
            if (node[i].pos)
                cout << node[i].a << " ";
            else
                cout << -node[i].a << " ";
        }
        if (node[n - 1].pos)
            cout << node[n - 1].a << endl;
        else
            cout << -node[n - 1].a << endl;
    }
}