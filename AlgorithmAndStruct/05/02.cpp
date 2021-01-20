#include <bits/stdc++.h>
using namespace std;

//allocate all pointers to specific sizes
void init(bool **mat, bool *find, int n)
{
    for (int i = 0; i < n; i++)
    {
        mat[i] = new bool[n];
        memset(mat[i], false, sizeof(bool) * n);
    }
    memset(find, false, sizeof(bool) * n);
}

//read data from stdin
void readData(bool **mat, int n, int &d)
{
    for (int i = 0; i < n; i++) //input
    {
        int x, y;
        cin >> x >> y;
        mat[x][y] = mat[y][x] = true;
    }
    cin >> d;
}

//depth-first search
void dfs(bool **mat, bool *find, int n, int x = 0)
{
    find[x] = true;
    cout << x << " ";
    for (int i = 0; i < n; i++)
        if (!find[i] && mat[x][i])
            dfs(mat, find, n, i);
}

//width-first search
void bfs(bool **mat, bool *find, int n, int x = 0)
{
    queue<int> q;
    cout << x << " ";
    find[x] = true;
    q.push(x);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
            if (mat[temp][i] && !find[i])
            {
                cout << i << " ";
                q.push(i);
                find[i] = true;
            }
    }
}

//start to process functions
void run(bool **mat, bool *find, int n, int x)
{
    for (int i = 0; i < n; i++) //dfs
        if (!find[i])
            dfs(mat, find, n, i);

    cout << endl;

    memset(find, false, sizeof(bool) * n); //bfs
    bfs(mat, find, n);

    cout << endl;

    memset(find, false, sizeof(bool) * n);
    find[x] = true;             // this is equal to delete the point
    for (int i = 0; i < n; i++) //dfs
        if (!find[i])
            dfs(mat, find, n, i);

    cout << endl;

    memset(find, false, sizeof(bool) * n);
    find[x] = true;
    bfs(mat, find, n); //bfs
}

void destory(bool **mat, const bool *find, int n)
{
    for (int i = 0; i < n; i++)
        delete mat[i];
    delete mat;
    delete find;
}

int main(int argc, char *argv[])
{
    int pointNum, edgeNum, deleteNum;
    cin >> pointNum >> edgeNum;
    bool **mat = new bool *[pointNum];
    bool *find = new bool[pointNum];

    init(mat, find, pointNum);
    readData(mat, edgeNum, deleteNum);
    run(mat, find, pointNum, deleteNum);
    destory(mat, find, pointNum);
    return 0;
}