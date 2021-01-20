#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    for (int o = 1; o <= n; o++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a + b > c)
            cout << "Case #" << o << ": true" << endl;
        else
            cout << "Case #" << o << ": false" << endl;
    }
    return 0;
}