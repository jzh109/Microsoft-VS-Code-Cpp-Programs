#include <cmath>
#include <iostream>
using namespace std;

const double eps = 1e-6;
int n;
double y;

double func(double x)
{
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * x * x - y * x;
}

int main(void)
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf", &y);
        double l = 0, r = 100, midl, midr;
        while (r - l > eps)
        {
            midl = (2 * l + r) / 3;
            midr = (2 * r + l) / 3;
            if (func(midl) > func(midr))
                l = midl;
            else
                r = midr;
        }
        printf("%.4lf\n", func(r));
    }
}