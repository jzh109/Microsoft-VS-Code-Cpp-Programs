#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int a, rem = 0, ma = 0;
    bool j = true;
    for (int i = 0; i < 12; i++)
    {
        rem += 300;
        cin >> a;
        ma += (rem - a) / 100 * 100;
        rem -= a + (rem - a) / 100 * 100;
        if (rem < 0)
        {
            cout << '-' << i + 1 << endl;
            j = false;
            break;
        }
    }
    if (j)
        cout << rem + ma * 1.2 << endl;
    return 0;
}