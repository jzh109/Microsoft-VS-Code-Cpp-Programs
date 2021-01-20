#include <cmath>
#include <iostream>
using namespace std;

const double eps = 1e-6;
const double pi = acos(-1.0);
double x, y, l, d;

double fun(double i)
{
    return (x - l * sin(i) - d / cos(i)) / tan(i);
}

int main()
{
    while (~scanf("%lf%lf%lf%lf", &x, &y, &l, &d))
    {
        double ll = 0, rr = pi / 2, midl, midr;
        while (rr - ll > eps)
        {
            midl = (2 * ll + rr) / 3;
            midr = (ll + 2 * rr) / 3;
            if (fun(midl) < fun(midr))
                rr = midr;
            else
                ll = midl;
        }
        if (fun(ll) > -y)
            printf("yes\n");
        else
            printf("no\n");
    }
}
