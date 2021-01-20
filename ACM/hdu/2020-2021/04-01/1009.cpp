#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, a[105], min, pos, temp;
    while (cin >> n, n)
    {
        min = 0x3F3F3F3F;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp < min)
            {
                min = temp;
                pos = i;
            }
            a[i] = temp;
        }
        swap(a[0], a[pos]);
        for (int i = 0; i < n - 1; i++)
            cout << a[i] << " ";
        cout << a[n - 1] << endl;
    }
}