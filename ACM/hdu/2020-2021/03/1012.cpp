#include <cstdio>
#include <iostream>
#define M 1000001
using namespace std;

long long int num[M], sum[M];

void dabiao()
{
    num[0] = sum[0] = 0;
    for (int i = 1; i < M; i++)
    {
        num[i] = num[i - 1] + i;
        sum[i] = num[i] + sum[i - 1];
    }
}
int twosearch1(long long int n)
{
    int left = 0, right = M - 1, middle;
    while (left + 1 != right) //这样找到   sum[left] < n <=sum[right]
    {
        middle = left + (right - left) / 2; //防止溢出

        if (sum[middle] < n)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }
    return right;
}
int twosearch2(int right, long long int n)
{
    int left = 0, middle;
    while (left + 1 != right)
    {
        middle = left + (right - left) / 2;
        if (num[middle] < n)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }
    return right;
}
int main()
{
    int t;
    scanf("%d", &t);
    dabiao();
    while (t--)
    {
        long long int n;
        int ans1, ans2, ans3;
        scanf("%I64d", &n);
        ans1 = twosearch1(n);
        ans2 = twosearch2(ans1, n - sum[ans1 - 1]);
        ans3 = n - sum[ans1 - 1] - num[ans2 - 1];
        printf("%d %d %d\n", ans1, ans2, ans3);
    }
    return 0;
}
