#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s;
    int n;
    int k = 0;
    while (cin >> s)
    {
        if (s == '@')
            break;
        cin >> n;
        if (k == 1)
            cout << endl;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                cout << string(n - 1, ' ') << s << endl;
            else if (i == n)
                cout << string(2 * i - 1, s) << endl;
            else
                cout << string(n - i, ' ') << s << string(2 * (i - 1) - 1, ' ') << s << endl;
        }
        k = 1;
    }
    return 0;
}