#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    double *a = new double[10];
    a[0] = 1;
    for (int i = 1; i < 10; i++)
        a[i] = 1.0 * a[i - 1] / (1.0 * i);
    for (int i = 1; i < 10; i++)
        a[i] += a[i - 1];
    for (int i = 0; i < 3; i++)
        cout << i << " " << a[i] << endl;
    for (int i = 3; i < 10; i++)
        printf("%d %.9lf\n", i, a[i]);
    return 0;
}