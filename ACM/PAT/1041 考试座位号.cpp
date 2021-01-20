#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    string id;
    int a;
    int b;
} Node;

int main(int argc, char *argv[])
{
    int m, n;
    Node node[10005];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> node[i].id >> node[i].a >> node[i].b;
    cin >> m;
    while (m--)
    {
        int temp;
        cin >> temp;
        for (int i = 0; i < n; i++)
            if (node[i].a == temp)
            {
                cout << node[i].id << " " << node[i].b << endl;
                break;
            }
    }
    return 0;
}