#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    ll a;
    cin >> n;
    while (n--)
    {
        cin >> a;
        while (a != 1)
        {
            if (a & 1)
                break;
            else
                a >>= 1;
        }
        cout << (a == 1 ? "NO" : "YES") << endl;
    }
    return 0;
}