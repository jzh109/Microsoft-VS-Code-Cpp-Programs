#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int x, y;
    int num;
} node[3009];

bool cmp(Node &a, Node &b)
{
    return a.x < b.x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 3 * n; i++)
        {
            cin >> node[i].x >> node[i].y;
            node[i].num = i + 1;
        }
        sort(node, node + 3 * n, cmp);
        int cnt = 0;
        for (int i = 0; i < 3 * n; i++)
        {
            if (cnt == 2)
            {
                cout << node[i].num << endl;
            }
            else
            {
                cout << node[i].num << " ";
            }
            cnt = cnt % 3;
        }
    }
    return 0;
}