#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int F1[40];
void init()
{
    F1[0] = 0, F1[1] = 1;
    for (int i = 2; i < 40; i++)
    {
        F1[i] = F1[i - 1] + F1[i - 2];
    }
}
struct Matrix
{
    int mat[3][3];
};
Matrix Multiply(Matrix x, Matrix y)
{
    Matrix temp;
    memset(temp.mat, 0, sizeof(temp.mat));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                temp.mat[i][j] += (x.mat[i][k] * y.mat[k][j] % 10000);
            }
        }
    return temp;
}
Matrix Fast_Power(Matrix a, int n)
{
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for (int i = 0; i < 2; i++)
        res.mat[i][i] = 1;
    while (n)
    {
        if (n & 1)
            res = Multiply(res, a);
        n >>= 1;
        a = Multiply(a, a);
    }
    return res;
}
int find_head(int n)
{
    double t = -0.5 * log10(5.0) + (double)n * log10((1 + pow(5.0, 0.5)) / 2);
    t = t - floor(t);
    double x = pow(10, t + 3);
    return (int)floor(x);
}
int main()
{
    init();
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n < 40)
            printf("%d\n", F1[n]);
        else
        {
            int head = find_head(n) % 10000;
            Matrix temp, ans;
            temp.mat[0][0] = 0;
            temp.mat[0][1] = temp.mat[1][0] = temp.mat[1][1] = 1;
            ans = Fast_Power(temp, n - 1);
            int ending = ans.mat[1][1] % 10000;
            printf("%04d...%04d\n", head, ending);
        }
    }
    return 0;
}