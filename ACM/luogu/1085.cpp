#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int res = 0, a, b, maxx = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> a >> b;
        if (maxx < a + b)
        {
            maxx = a + b;
            res = i + 1;
        }
    }
    cout << res << endl;
    return 0;
}