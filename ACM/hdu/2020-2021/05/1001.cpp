#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l;
    char a[10000];
    cin >> n;
    while (n--)
    {
        cin >> a;
        l = strlen(a);
        int k = 1;
        for (int i = 0; i < l; i++)
        {
            if (a[i + 1] == a[i])
                k++;
            else
            {
                if (k == 1)
                    cout << a[i];
                else
                    cout << k << a[i];
                k = 1;
            }
        }
        cout << endl;
    }
    return 0;
}