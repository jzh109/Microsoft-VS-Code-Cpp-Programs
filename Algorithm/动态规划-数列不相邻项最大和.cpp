#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 1005

int dp_opt(int n, int opt[], int arr[])
{
    if (n == 1)
        cout << arr[0] << endl;
    else
    {
        opt[0] = arr[0];
        opt[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            opt[i] = max(arr[i] + opt[i - 2], opt[i - 1]);
        }
    }
}

int main()
{
    int arr[MAXSIZE], opt[MAXSIZE] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp_opt(n, opt, arr);

    cout << opt[n - 1] << endl;
    return 0;
}

/*
4 1 1 9 1 => n - 1: 13

1 2 4 1 8 7 3 => n - 1: 15 
*/