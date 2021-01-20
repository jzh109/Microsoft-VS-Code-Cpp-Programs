#include <bits/stdc++.h>
using namespace std;

void init(int *list, int n)
{
    for (int i = 0; i <= n; i++)
        list[i] = i;
}

int findx(int *father, int x)
{
    if (father[x] == x)
        return x;
    return father[x] = findx(father, father[x]);
}

void merge(int *father, int x, int y)
{
    int a = findx(father, x), b = findx(father, y);
    if (a == b)
        return;
    father[a] = b;
}

void getMatrix(bool **mat, int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
}

int process(bool **relation, int *father, int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (relation[i][j] && !(findx(father, i) == findx(father, j)))
                merge(father, i, j);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (relation[i][j] && !(findx(father, i) == findx(father, j)))
                merge(father, i, j);
    set<int> s;
    s.clear();

    for (int i = 1; i <= n; i++)
        s.insert(father[i]);
    return s.size();
}

void destory(bool **r, int *f)
{
    delete r;
    delete f;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int *father = new int[n + 1];
    bool **relation = new bool *[n + 1];
    for (int i = 0; i <= n; i++)
        relation[i] = new bool[n + 1];
    init(father, n);
    getMatrix(relation, n);
    cout << process(relation, father, n) << endl;
    destory(relation, father);
    return 0;
}