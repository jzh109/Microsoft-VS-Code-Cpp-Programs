#include <iostream>
using namespace std;
int main()
{
    int m, n, a[105][105] = {0}, x[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, y[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    char c;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == '*')
            {
                a[i][j] = -1;
                for (int k = 0; k <= 7; k++)
                    if (a[i + x[k]][j + y[k]] != -1)
                        a[i + x[k]][j + y[k]]++;
            }
        }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[i][j] == -1)
                cout << "*";
            else
                cout << a[i][j];
        cout << endl;
    }
    return 0;
}