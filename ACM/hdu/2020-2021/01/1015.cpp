#include <bits/stdc++.h>
using namespace std;
int n;
struct point
{
    double x, y, dis;
} st, p[100009];
bool cmp(point a, point b)
{
    if (a.dis != b.dis)
        return a.dis < b.dis;
    return a.x < b.x;
}
double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
    double sml;
    while (scanf("%d", &n) && n)
    {
        st.x = st.y = 1000000.0;
        sml = 1000000.0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            st.x = min(st.x, p[i].x);
            st.y = min(st.y, p[i].y);
        }
        for (int i = 0; i < n; i++)
            p[i].dis = dist(p[i], st);
        sort(p, p + n, cmp);
        for (int i = 1; i < n; i++)
            if (dist(p[i], p[i - 1]) < sml)
                sml = dist(p[i], p[i - 1]);
        printf("%.2lf\n", sml / 2);
    }
    return 0;
}