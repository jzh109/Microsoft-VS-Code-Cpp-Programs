#include <cmath>
#include <iostream>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-7;
int n;
double r, R, h, v;

double vol(double h1)
{
    double r1 = h1 / h * (R - r) + r;
    return pi * h1 * (r1 * r1 + r * r + r * r1) / 3;
}

int main(void)
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf%lf%lf%lf", &r, &R, &h, &v);
        double min = 0, max = h, mid;
        while (max - min > eps)
        {
            mid = (min + max) / 2;
            if (vol(mid) > v)
                max = mid;
            else
                min = mid;
        }
        printf("%.6lf\n", mid);
    }
}