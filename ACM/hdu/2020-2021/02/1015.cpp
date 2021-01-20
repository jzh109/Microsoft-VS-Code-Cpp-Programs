#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    while (cin >> t)
    {
        while (t--)
        {
            char c;
            int a, b;
            cin >> c >> a >> b;
            switch (c)
            {
            case '+':
                cout << a + b << endl;
                break;
            case '-':
                cout << a - b << endl;
                break;
            case '*':
                cout << a * b << endl;
                break;
            case '/':
                if (a % b == 0)
                    cout << a / b << endl;
                else
                    printf("%.2lf\n", (double)(a) / b);
            }
        }
    }
    return 0;
}