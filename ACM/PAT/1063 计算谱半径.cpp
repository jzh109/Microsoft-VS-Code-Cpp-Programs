#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef struct NODE
{
    int a;
    int b;
    double dis;
    bool operator<(const NODE a) const
    {
        return dis > a.dis;
    }
} Node;

int main()
{
    int n;
    Node node[10006];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> node[i].a >> node[i].b;
        a = node[i].a;
        b = node[i].b;
        node[i].dis = sqrt(a * a + b * b);
    }
    sort(node, node + n);
    printf("%.2f\n", node[0].dis);
    return 0;
}