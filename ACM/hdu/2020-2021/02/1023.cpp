#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, start, end;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        end = a.length() - 1;
        start = a[0] == '-' ? 1 : 0;
        while (a[end] == '0')
            end--;
        reverse(a.begin() + start, a.begin() + 1 + end);
        cout << a << endl;
    }
    return 0;
}