#include <cmath>
#include <cstdio>
using namespace std;
typedef double DB;
const DB EPS = 1e-6;
struct point
{
    DB x, y;
} A, B, C, D;
int P, Q, R, T;
inline DB dis(point A, point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
inline DB calc(DB p1, DB p2)
{
    point X, Y;
    X.x = p1 * (B.x - A.x) + A.x;
    X.y = p1 * (B.y - A.y) + A.y;
    Y.x = p2 * (D.x - C.x) + C.x;
    Y.y = p2 * (D.y - C.y) + C.y;
    return dis(A, X) / P + dis(X, Y) / R + dis(Y, D) / Q;
}
inline DB get(DB p1)
{
    DB l = 0, r = 1.0;
    while (r - l > EPS)
    {
        DB lmid = l + (r - l) / 3.0, rmid = r - (r - l) / 3.0;
        if (calc(p1, lmid) <= calc(p1, rmid))
            r = rmid;
        else
            l = lmid;
    }
    return calc(p1, l);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
        scanf("%d%d%d", &P, &Q, &R);
        DB l = 0, r = 1.0;
        while (r - l > EPS)
        {
            DB lmid = l + (r - l) / 3.0, rmid = r - (r - l) / 3.0;
            if (get(lmid) <= get(rmid))
                r = rmid;
            else
                l = lmid;
        }
        printf("%.2lf\n", get(l));
    }
    return 0;
}