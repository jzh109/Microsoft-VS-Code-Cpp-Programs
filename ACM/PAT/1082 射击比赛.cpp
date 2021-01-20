#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    string id;
    int x, y;
    double dis;
    bool operator<(const NODE &a) const
    {
        return dis < a.dis;
    }
} Node;

int main(int argc, char const *argv[])
{
    Node node[10005];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].id >> node[i].x >> node[i].y;
        node[i].dis = sqrt(node[i].x * node[i].x + node[i].y * node[i].y);
    }
    sort(node, node + n);
    cout << node[0].id << " " << node[n - 1].id << endl;
    return 0;
}
