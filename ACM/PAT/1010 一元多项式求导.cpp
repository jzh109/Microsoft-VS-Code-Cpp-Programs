#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int k, n;
} node[1005];

int main(int argc, const char **argv)
{
    int n = 0;
    while (cin >> node[n].k >> node[n].n)
        n++;
    if (n == 1 && node[0].n == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    if (node[n - 1].n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << node[i].k * node[i].n << " " << node[i].n - 1 << endl;
            else
                cout << node[i].k * node[i].n << " " << node[i].n - 1 << " ";
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (i == n - 2)
                cout << node[i].k * node[i].n << " " << node[i].n - 1 << endl;
            else
                cout << node[i].k * node[i].n << " " << node[i].n - 1 << " ";
        }
    }
    return 0;
}