#include <bits/stdc++.h>
using namespace std;

//initialize the arrays
void init(bool **m, bool *f, int n)
{
    if (n <= 0)
        exit(0);
    for (int i = 0; i < n; i++)
    {
        m[i] = new bool[n];
        f[i] = false;
    }
}

//read data from stdin
void readData(bool **mat, int n)
{
    if (n <= 0 || mat == nullptr)
        exit(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
}

//use recurrence of dfs find all related points
void dfs(bool **mat, bool *find, int n, int x = 0)
{
    if (n <= 0 || x < 0 || mat == nullptr || find == nullptr)
        exit(0);
    find[x] = true;
    for (int i = 0; i < n; i++)
        if (!find[i] && mat[x][i])
            dfs(mat, find, n, i);
}

//process request
void process(bool **mat, bool *find, int n, int &res)
{
    if (mat == nullptr || find == nullptr || n <= 0)
        exit(0);
    for (int i = 0; i < n; i++)
        if (!find[i])
        {
            dfs(mat, find, n, i);
            //cout << i << endl;
            res++;
        }
}

//release the memory
void destory(bool **mat, bool *find, int n)
{
    if (mat == nullptr || find == nullptr || n <= 0)
        exit(0);
    for (int i = 0; i < n; i++)
        delete mat[i];
    delete mat;
    delete find;
}

int main(int argc, char *argv[])
{
    int n, res = 0;
    cin >> n;
    bool *find = new bool[n];
    bool **mat = new bool *[n];
    if (n <= 0)
        return 0;
    init(mat, find, n);
    readData(mat, n);
    process(mat, find, n, res);
    cout << res << endl;
    destory(mat, find, n);
    return 0;
}