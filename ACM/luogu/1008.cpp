#include <bits/stdc++.h>
using namespace std;
inline int num1(int a) { return a - a / 10 * 10; }

inline int num2(int a) { return (a / 10 * 10 - a / 100 * 100) / 10; }

inline int num3(int a) { return a / 100; }

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    for (int i = 123; i <= 329; i++)
    {
        if (i % 5 == 0)
            continue;
        bool a[9] = {false};
        a[num1(i) - 1] = true;
        a[num2(i) - 1] = true;
        a[num3(i) - 1] = true;
        a[num1(2 * i) - 1] = true;
        a[num2(2 * i) - 1] = true;
        a[num3(2 * i) - 1] = true;
        a[num1(3 * i) - 1] = true;
        a[num2(3 * i) - 1] = true;
        a[num3(3 * i) - 1] = true;
        if (a[0] && a[1] && a[2] && a[3] && a[4] && a[5] && a[6] && a[7] && a[8])
            cout << i << " " << i * 2 << " " << i * 3
                 << endl;
    }
    return 0;
}