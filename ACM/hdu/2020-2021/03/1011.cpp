#include <cmath>
#include <iostream>
using namespace std;

double dis(double ax, double ay, double bx, double by)
{
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int ax, ay, bx, by, cx, cy, dx, dy, p, q, r, t;
    cin >> t;
    while (t--)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> p >> q >> r;
    }
}