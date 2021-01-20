#include <algorithm>
#include <math.h>
#include <stdio.h>
#define g 9.8
using namespace std;

int main()
{
    int cas;
    double x, y, v;
    double delt;
    double re1, re2, re;

    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%lf%lf%lf", &x, &y, &v);
        delt = x * x - 2 * g * x * x * 1.0 * (y + g * x * x / (2 * v * v) * 1.0) / (v * v) * 1.0;
        if (delt < 0)
            printf("-1\n");
        else
        {
            re1 = (x - sqrt(delt)) * v * v * 1.0 / (g * x * x);
            re2 = (x + sqrt(delt)) * v * v * 1.0 / (g * x * x);
            re1 = atan(re1);
            re2 = atan(re2);
            re = min(re1, re2);
            printf("%.6f\n", re);
        }
    }
    return 0;
}
