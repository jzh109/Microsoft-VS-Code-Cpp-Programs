#include <stdio.h>
int judge(int n, int m);
int main(void)
{
    int i, N, n, m;
    scanf("%d", &N);
    getchar();
    getchar();
    for (i = 0; i < N; i++)
    {
        int j = 1;

        while (scanf("%d%d", &n, &m) == 2 && !(n == 0 && m == 0))
        {
            int cnt = judge(n, m);
            printf("Case %d: %d\n", j++, cnt);
        }
        if (i < N - 1)
            printf("\n");
    }
    return 0;
}
int judge(int n, int m)
{
    int cnt = 0, i, j;
    for (i = 1; i < n; i++)
        for (j = i + 1; j < n; j++)
            if ((i * i + j * j + m) % (i * j) == 0)
                cnt++;
    return cnt;
}