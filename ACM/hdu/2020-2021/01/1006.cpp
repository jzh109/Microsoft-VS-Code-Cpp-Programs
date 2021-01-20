#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1007;
struct node
{
    int t;    //time to get here
    int p;    //parent node index
    int c;    //c
    double w; // weight
} num[N];
int n, r;

int find()
{
    int pos;
    double max = 0;
    for (int i = 1; i <= n; i++)
        if (num[i].w > max && i != r)
        {
            max = num[i].w;
            pos = i;
        }
    return pos; // return node index with max weight
}

int main()
{
    int i, j, a, b, pos, res, f;
    while (scanf("%d%d", &n, &r), n || r)
    {
        res = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &num[i].c);
            num[i].w = num[i].c;
            num[i].t = 1;
            res += num[i].c;
        }
        for (i = 1; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            num[b].p = a;
        }
        i = n;
        while (i > 1)
        {
            pos = find();
            num[pos].w = 0; //make it 0 stands for being colored
            f = num[pos].p; //cache max weight node's parent node index
            res += num[pos].c * num[f].t;
            for (j = 1; j <= n; j++)
                if (num[j].p == pos)
                    num[j].p = f; // merge colored node
            num[f].c += num[pos].c;
            num[f].t += num[pos].t;
            num[f].w = (double)num[f].c / num[f].t;
            i--;
        }
        printf("%d\n", res);
    }
    return 0;
}