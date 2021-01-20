#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int element;
    int num = 0;

    bool operator<(const Node &a) const
    {
        return element < a.element;
    }
} node;

int main(int argc, char const *argv[])
{
    string str;
    bool find = false;
    int num = 0;
    node nodes[105];
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        find = false;
        for (int j = 0; j < num; j++)
        {
            if (nodes[j].element == str[i])
            {
                nodes[j].num++;
                find = true;
            }
        }
        if (!find)
        {
            nodes[num].element = str[i];
            nodes[num].num++;
            num++;
        }
    }
    sort(nodes, nodes + num);
    for (int i = 0; i < num; i++)
        cout << nodes[i].element - '0' << ":" << nodes[i].num << endl;
    return 0;
}
