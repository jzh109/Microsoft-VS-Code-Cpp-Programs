#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    double s = 0;
    int k, i;
    cin >> k;
    for (i = 1; s <= k; i++)
        s += 1.0 / i;
    cout << i - 1 << endl;
    return 0;
}