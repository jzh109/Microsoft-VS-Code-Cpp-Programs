#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, res, temp;
        cin >> a;
        for (res = 0; res < 10; res++)
        {
            temp = res * a * a;
            if (a == (temp - temp / 100 * 100) || a == (temp - temp / 1000 * 1000) || a == (temp - temp / 10 * 10))
                break;
        }
        if (res != 10)
            cout << res << " " << temp << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
