#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    while (~scanf("%d", &n), n)
    {
        string s;
        getchar();
        getline(cin, s);
        char a[n][n] = {{0}};
        int j = 0, ca = 1, cnt = 0;
        for (int i = 0; cnt != s.length(); i++)
        {
            while (true)
            {
                char c = s[cnt];
                a[i][j] = s[cnt++];
                if (j == 0 && (i & 1))
                {
                    ca = 1;
                    break;
                }
                else if (j == n - 1 && !(i & 1))
                {
                    ca = -1;
                    break;
                }
                j += ca;
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < s.length() / n; i++)
            {
                printf("%c", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}