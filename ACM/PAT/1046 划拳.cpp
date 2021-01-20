#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, resa = 0, resb = 0;
    cin >> n;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b == a + c && d != a + c)
            resb++;
        else if (d == a + c && b != a + c)
            resa++;
    }
    cout << resa << " " << resb << endl;
}