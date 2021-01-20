#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

struct Task
{
    int val;
    int from, to;
    bool operator<(const Task &a) const
    {
        return to < a.to;
    }
} tasks[MAXSIZE];

void constructOPT(int opt[], int prev[], int n)
{
    opt[1] = tasks[1].val;
    for (int i = 2; i <= n; i++)
    {
        opt[i] = max(opt[i - 1], tasks[i].val + opt[prev[i]]);
    }
}

int main()
{
    int n, prev[MAXSIZE] = {0}, opt[MAXSIZE] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tasks[i].val;
        cin >> tasks[i].from;
        cin >> tasks[i].to;
    }
    sort(tasks + 1, tasks + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (tasks[j].to <= tasks[i].from)
            {
                prev[i] = j;
                break;
            }
        }
    } //建立prev[]数组

    constructOPT(opt, prev, n);

    cout << opt[n] << endl;
    return 0;
}

/*
val from    to
8
5   1   4
1   3   5
8   0   6
4   4   7
6   3   8
3   5   9
2   6   10
4   8   11
res: 13
*/