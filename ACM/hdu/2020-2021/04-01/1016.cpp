#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
    int T, n, v;
    int w;
    int a[105];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &v, &w);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        if (a[0] > w)
        {
            printf("0 0.00\n");
        }
        else
        {
            double sum = 0;
            int i;
            for (i = 0; i < n; i++)
            {
                if ((sum + a[i]) / (i + 1) <= w)
                {
                    sum += a[i];
                }
                else
                {
                    break;
                }
            }
            printf("%d %.2lf\n", i * v, sum / i / 100);
        }
    }
    return 0;
}