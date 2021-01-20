#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-6;

int n, t, f, temp;
double a[10005], l, r, mid, sum;

bool func(double x)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += int(a[i] / x);
    if (total >= f)
        return true;
    return false;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        sum = 0;
        scanf("%d%d", &n, &f);
        f += 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            a[i] = temp * temp * pi;
            sum += a[i];
        }
        l = 0;
        r = sum / f;
        do
        {
            mid = (l + r) / 2;
            if (func(mid))
                l = mid;
            else
                r = mid;
        } while (r - l > eps);
        printf("%.4lf\n", mid);
    }
}