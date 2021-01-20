#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int o = 1; o <= n; o++)
    {
        char a[1005] = {0};
        char b[1005] = {0};
        int k = 0;
        cin >> a >> b;
        int lena = strlen(a);
        int lenb = strlen(b);
        reverse(a, a + lena);
        reverse(b, b + lenb);
        int x = max(lena, lenb);
        for (int i = 0; i < lena; i++)
            a[i] -= 48;
        for (int i = 0; i < lenb; i++)
            b[i] -= 48;
        char res[x + 2] = {0};
        for (int i = 0; i < x; i++)
        {
            res[i] = (k + a[i] + b[i]) % 10;
            k = (k + a[i] + b[i]) / 10;
            res[i] += 48;
        }
        res[x] = k;
        for (int i = 0; i < lena; i++)
            a[i] += 48;
        for (int i = 0; i < lenb; i++)
            b[i] += 48;
        reverse(a, a + lena);
        reverse(b, b + lenb);
        reverse(res, res + strlen(res));
        cout << "Case " << o << ":" << endl;
        cout << a << " + " << b << " = " << res << endl;
        if (o != n)
            cout << endl;
    }
}