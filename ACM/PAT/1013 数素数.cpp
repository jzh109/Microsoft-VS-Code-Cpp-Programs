// #include <bits/stdc++.h>
// using namespace std;

// bool prime(int a)
// {
//     if (a == 1)
//         return false;
//     int max = sqrt(a) + 1;
//     for (int i = 2; i <= max; i++)
//         if ((a / i) * i == a)
//             return false;
//     return true;
// }

// int main(int argc, char const *argv[])
// {
//     int from, to, cnt = 2;
//     int a[10005] = {0};
//     cin >> from >> to;
//     a[1] = 2;
//     for (int i = 3; i <= 50010; i += 2)
//     {
//         if (prime(i))
//             a[cnt++] = i;
//     }
//     if (from == to)
//     {
//         cout << a[from] << endl;
//         return 0;
//     }
//     for (int i = 1; i <= to - from + 1; i++)
//     {
//         if (i % 10 == 0 || i == to - from + 1)
//             cout << a[from + i - 1] << endl;
//         else
//             cout << a[from + i - 1] << " ";
//     }
//     return 0;
// }

#include <math.h>
#include <stdio.h>

int IsPrime(int); //判断是否为素数

int main()
{
    int M, N, a = 0, b = 2, count = 0;
    scanf("%d %d", &M, &N);
    while (a < N)
    {
        if (IsPrime(b))
        {
            a++; //a用来记录现在是第几个素数
            if (a >= M)
            {
                printf("%d", b);
                count++; //count用来记录已经输出多少个素数
                if (count % 10 == 0)
                {
                    printf("\n");
                }
                else if (a != N)
                {
                    printf(" ");
                }
            }
        }
        b++;
    }
}

int IsPrime(int b)
{
    int flag = 1;
    for (int i = 2; i <= sqrt(b); i++)
    {
        if (b % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}