#include <iostream>
using namespace std;

inline void snakeLikeMat(int **a, int n)
{
    int cnt = 1;
    int full = n * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i & 1)
            {
                a[j][i - j] = cnt++;
            }
            else
            {
                a[i - j][j] = cnt++;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i & 1)
            {
                a[n - 1 - j][n - 1 - i + j] = full--;
            }
            else
            {
                a[n - 1 - i + j][n - 1 - j] = full--;
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    int n = 0;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    snakeLikeMat(a, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%-4d", a[j][i]);
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}