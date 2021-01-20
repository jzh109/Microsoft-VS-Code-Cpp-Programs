#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1000 + 10;
#define met(a, b) memset(a, b, sizeof(a))
int map[maxn][maxn];
int used[maxn], d[maxn];
int n, m;
int find(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (map[x][i] == true && used[i] == false)
        {
            used[i] = 1;
            if (d[i] == 0 || find(d[i]))
            {
                d[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int x, y;
        int sum = 0;
        met(map, 0);
        met(d, 0);
        for (int i = 0; i < n; i++)
        {
            scanf("%d: (%d) ", &x, &m);
            while (m--)
            {
                scanf("%d,", &y);
                map[x][y] = 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            met(used, 0);
            if (find(j))
                sum++;
        }
        printf("%d\n", n - sum / 2);
    }
    return 0;
}