#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    int val;
    bool ans;
} Node;

int main(int argc, char const *argv[])
{
    int m, n;
    Node node[10005];
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> node[i].val;
    for (int i = 0; i < n; i++)
        cin >> node[i].ans;
    while (m--)
    {
        bool temp;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (node[i].ans ^ temp)
                res += node[i].val;
        }
        cout << res << endl;
    }
    return 0;
}
