#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, a[105][105] = {0}, *sum;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    sum = a[n];
    for (int i = n - 1; i > 0; i--)
        for (int j = 1; j <= i; j++)
            sum[j] = max(sum[j], sum[j + 1]) + a[i][j];
    cout << sum[1] << endl;
    return 0;
}