//高斯赛德尔迭代法，解线性方程组，高等数值计算
//开发人员：chenshuai  开发日期：2019.11.5  邮箱：chenshuai0614@hrbeu.edu.cn
#include "pch.h"
#include <iostream>
using namespace std;
#include <iomanip> //参数化输入/输出
#include <vector>
#define n 100                                                                                  //矩阵大小
#define epsilon 0.0001                                                                         //精度
vector<double> Gauss_seidel(vector<vector<double>> a, vector<double> b, vector<double> x_new); //申明高斯赛德尔迭代方法求解函数
vector<double> Gauss_seidel(vector<vector<double>> a, vector<double> b, vector<double> x_new)
{
    int num = size(b), n_cishu = 0;
    double sum = 0, max_precision = 0;
    ;
    vector<double> x_old(num);
    do
    {
        n_cishu++;
        for (int j = 0; j < num; j++)
        {
            x_old[j] = x_new[j];
        }
        for (int j = 0; j < num; j++)
        {
            sum = 0;
            for (int k = 0; k < num; k++)
            {
                if (j != k)
                {
                    sum = sum - a[j][k] * x_old[k];
                }
            }
            x_new[j] = (sum + b[j]) / a[j][j];
            max_precision = 0;
            for (int i = 0; i < num; i++)
            {
                sum = fabs(x_new[i] - x_old[i]);
                if (sum > max_precision)
                {
                    max_precision = sum;
                }
            }
            x_old[j] = x_new[j];
        }
    } while (max_precision > epsilon);
    //残差计算
    double max_residual = 0;
    for (int i = 0; i < num; i++)
    {
        sum = b[i];
        for (int j = 0; j < num; j++)
        {
            sum = sum - a[i][j] * x_new[j];
        }
        if (sum > max_residual)
        {
            max_residual = sum;
        }
    }
    cout << "所需步数：" << n_cishu << "残差：" << fixed << setprecision(8) << setw(10) << max_residual << endl;
    return x_new;
}
int main()
{
    vector<vector<double>> a{{5, -1, 2}, {-1, 3, 1}, {3, -2, 8}};
    a.resize(n, vector<double>(n)); //定义线性方程组系数矩阵A
    vector<double> b(n){-9, 10, 5}; //定义线性方程组右边列向量B
    vector<double> x(n);            //初始化向量
    // a[0][0] = 3, a[0][1] = -1, b[0] = 2;
    // for (int i = 1; i < n - 1; i++)
    // {
    //     a[i][i - 1] = -1;
    //     a[i][i] = 3;
    //     a[i][i + 1] = -1;
    //     b[i] = 1;
    // }
    // a[n - 1][n - 2] = -1;
    // a[n - 1][n - 1] = 3, b[n - 1] = 2;
    x = Gauss_seidel(a, b, x);
}