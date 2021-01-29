#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
double cable[10005];
const double eps = 1e-6;
int n, k;
int getNum(double Len)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += cable[i] / Len;
    return sum;
}
int main()
{
    while (scanf("%d%d", &n, &k) == 2 && (n || k))
    {
        double L = 0, R = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &cable[i]);
            R = max(R, cable[i]);
        }
        while (R - L >= eps)
        {
            double mid = (R + L) / 2;
            if (getNum(mid) < k)
                R = mid;
            else
                L = mid;
        }
        int t = R * 100;
        double ans = t / 100.0;
        printf("%.2lf\n", ans);
    }
    return 0;
}