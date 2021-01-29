#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    char a[100];
    while (cin >> a)
    {
        int len = strlen(a), x = 0, flag = 0;
        if (len == 3 && a[0] == 'e' && a[1] == 'n' && a[2] == 'd')
            break;
        for (int i = 0; i < len; i++)
        {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                x++;
            if (i >= 2)
            {
                int s = 0, y = 0;
                for (int j = i; j >= i - 2; j--)
                {
                    if (a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' || a[j] == 'u')
                        s++;
                    else
                        y++;
                }
                if (s == 3 || y == 3)
                    flag = 1;
            }
            if (i > 0)
            {
                if (a[i] == a[i - 1] && a[i] != 'e' && a[i] != 'o')
                    flag = 1;
            }
        }
        if (x == 0)
            flag = 1;
        if (flag)
            cout << "<" << a << ">"
                 << " is not acceptable.\n";
        if (flag == 0)
            cout << "<" << a << ">"
                 << " is acceptable.\n";
    }
}