#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> n;
        int temp, max = -1, from = 0, to = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            sum += temp;
            if (max < sum)
            {
                max = sum;
                to = i;
            }
        }
        for (int i = from + 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
            }
        }
        cout << "Case " << cas << ":" << endl;
        cout << max << " " << from + 1 << " " << to + 1 << endl;
        if (cas != t)
            cout << endl;
    }
}