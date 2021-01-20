#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 105

bool dp_subset(int arr[], int n, int s)
{
    bool subset[n][s + 1];
    memset(subset, false, sizeof(subset));
    for (int i = 0; i < n; i++)
        subset[i][0] = true;
    subset[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < s + 1; j++) //"j" is "s" in different cases
        {
            if (arr[i] > j)
                subset[i][j] = subset[i - 1][j];
            else
                subset[i][j] = subset[i - 1][j - arr[i]] || subset[i - 1][j];
        }
    }

    return subset[n - 1][s + 1];
}

/*
if (s == 0)
        return true;
    else if (i == 0)
        return arr[0] == s;
    else if (arr[i] > s)
        return rec_subset(arr, i - 1, s);
*/

/*
                s
            j   0   1   2   3   4   5   6   7   8   9
arr[i]  i
3       0       1
34      1       1
4       2       1
12      3       1
5       4       1
2       5       1
*/

int main()
{
    int n, arr[MAXSIZE], s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> s;

    cout << dp_subset(arr, n, s) << endl;
    return 0;
}