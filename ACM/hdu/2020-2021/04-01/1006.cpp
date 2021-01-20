#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        printf("%.2f\n", sqrt((c - a) * (c - a) + (b - d) * (b - d)));
    }
}
