#include <cmath>
#include <iostream>
using namespace std;

int n;
double y;
const double eps = 1e-6;

double func(double x)
{
    return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * x * x + 3 * x + 6;
}

int main(void)
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf", &y);
        if (func(0) > y || func(100) < y)
        {
            printf("No solution!\n");
            continue;
        }
        double l = 0, r = 100, mid;
        while (r - l > eps)
        {
            mid = (l + r) / 2;
            if (func(mid) > y)
                r = mid;
            else
                l = mid;
        }
        printf("%.4lf\n", r);
    }
}
