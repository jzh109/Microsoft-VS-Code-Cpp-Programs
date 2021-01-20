#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    char poll;
    int num = 0;
    bool find = false;
} Node;

int main(int argc, char const *argv[])
{
    Node a[1005], b[1005];
    int numa = 0, numb = 0;
    char c;
    bool find, less = false;
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        find = false;
        for (int j = 0; j < numa; j++)
        {
            if (a[j].poll == c)
            {
                a[j].num++;
                find = true;
                break;
            }
        }
        if (!find)
        {
            a[numa].poll = c;
            a[numa++].num++;
        }
    }
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        find = false;
        for (int j = 0; j < numb; j++)
        {
            if (b[j].poll == c)
            {
                b[j].num++;
                find = true;
                break;
            }
        }
        if (!find)
        {
            b[numb].poll = c;
            b[numb++].num++;
        }
    }
    if (numa < numb)
    {
        cout << "No " << numb - numa << endl;
        return 0;
    }
    for (int i = 0; i < numb; i++)
    {
        for (int j = 0; j < numa; j++)
        {
            if (a[j].poll == b[i].poll)
            {
                b[i].find = true;
                if (!less && a[j].num < b[i].num)
                {
                    less = true;
                }
                a[j].num -= b[i].num;
                break;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < numa; i++)
    {
        if (less)
        {
            res += a[i].num < 0 ? a[i].num : 0;
        }
        else
        {
            res += a[i].num;
        }
    }
    if (less)
        for (int i = 0; i < numb; i++)
            res += b[i].find ? 0 : -b[i].num;
    if (less)
        cout << "No " << abs(res) << endl;
    else
        cout << "Yes " << res << endl;
    return 0;
}