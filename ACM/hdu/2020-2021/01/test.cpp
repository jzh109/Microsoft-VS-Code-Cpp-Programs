#include <stdio.h>
int main()
{
    int M, N, num[1000], sum1 = 0, sum2 = 0, i, sum[100], mn, N1, j, k = 0;
    while (~scanf("%d %d", &M, &N), M && N)
    {
        mn = M * N;
        for (i = 0; i < N; i++)
            scanf("%d", &num[i]);

        for (i = 0; i < N - 1; i++)
            for (j = 0; j < N - i - 1; j++)
                if (num[j] < num[j + 1])
                {
                    N1 = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = N1;
                }
        N1 = N;
        j = 0;

        for (i = 0; i <= M * N && N1 > 0; i++, mn--)
        {
            if (mn <= num[j])
            {
                if (sum2 == 0)
                {
                    sum1++;
                    N1--;
                    j++;
                    continue;
                }
                sum2--;
                N1--;
                j++;
                continue;
            }
            sum2++;
        }
        printf("Case %d: %d\n", k + 1, sum1);
        k++;
        sum1 = 0;
        sum2 = 0;
    }
}
