#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    while (cin >> s)
    {
        char maxx = 0;
        for (char c : s)
            maxx = max(maxx, c);
        for (char c : s)
        {
            putchar(c);
            if (c == maxx)
                printf("(max)");
        }
        printf("\n");
    }
    return 0;
}