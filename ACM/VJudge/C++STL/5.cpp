#include <string>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    string str, out;
    while (cin >> str)
    {
        out.clear();
        int len = str.size(), left = 0, right;
        right = len - 1;
        if (len & 1)
        {
            for (int i = 0; i < len; i++)
            {
                if (i & 1)
                {
                    out += str[right--];
                }
                else
                {
                    out += str[left++];
                }
                if (left > right)
                    break;
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (i & 1)
                {
                    out += str[left++];
                }
                else
                {
                    out += str[right--];
                }
                if (left > right)
                    break;
            }
        }
        reverse(out.begin(), out.end());
        cout << out << endl;
    }
    system("pause");
    return 0;
}