#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int *a = new int[10];
    int h, res = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    cin >> h;
    sort(a, a + 10);
    for (int i = 0; i < 10; i++)
    {
        if (a[i] <= h + 30)
            res++;
        else
            break;
    }
    cout << res << endl;
    return 0;
}