#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int n, m;
struct point
{
    double x, y;
} p[100005];

double calc(double x, int i)
{
    double k = (p[i].y - p[i - 1].y) / (p[i].x - p[i - 1].x);
    return ((n * 1.0) / (x * x) + k * (x - p[i].x) + p[i].y);
}
int main()
{

    while (cin >> m >> n)
    {
        double ans = 0x3F3F3F3F;
        memset(p, 0, sizeof(p));
        for (int i = 0; i < m; i++)
            cin >> p[i].x >> p[i].y;
        if (n == 0)
        {
            cout << "0.000" << endl;
            continue;
        }
        for (int i = 1; i < m; i++)
        {
            double l = p[i - 1].x, r = p[i].x, lmid, rmid;
            while (r - l >= eps)
            {
                lmid = (l + r) / 2.0;
                rmid = (lmid + r) / 2.0;
                if (calc(lmid, i) <= calc(rmid, i))
                    r = rmid;
                else
                    l = lmid;
            }
            ans = min(calc(l, i), ans);
        }
        printf("%.3f\n", ans);
    }
    return 0;
}