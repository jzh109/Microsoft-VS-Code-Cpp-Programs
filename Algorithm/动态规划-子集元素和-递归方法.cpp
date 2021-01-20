#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 105

bool rec_subset(int arr[], int i, int s)
{
    if (s == 0)
        return true;
    else if (i == 0)
        return arr[0] == s;
    else if (arr[i] > s)
        return rec_subset(arr, i - 1, s);
    else
    {
        return rec_subset(arr, i - 1, s - arr[i]) || rec_subset(arr, i - 1, s);
    }
}

int main()
{
    int n, s, arr[MAXSIZE];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //cin >> s;

    cout << rec_subset(arr, n - 1, 9) << endl;
    cout << rec_subset(arr, n - 1, 10) << endl;
    cout << rec_subset(arr, n - 1, 11) << endl;
    cout << rec_subset(arr, n - 1, 12) << endl;
    cout << rec_subset(arr, n - 1, 13) << endl;
    cout << rec_subset(arr, n - 1, 14) << endl;
    return 0;
}