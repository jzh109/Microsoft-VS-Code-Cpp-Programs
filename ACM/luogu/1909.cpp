#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        int res = 0x3F3F3F3F, a, b;
        for (int i = 0; i < 3; i++)
        {
            cin >> a >> b;
            a = n % a == 0 ? n / a : n / a + 1;
            res = min(res, a * b);
        }
        cout << res << endl;
    }

    return 0;
}