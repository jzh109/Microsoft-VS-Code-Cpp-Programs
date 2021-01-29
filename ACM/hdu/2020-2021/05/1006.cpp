#include <iostream>
using namespace std;
int main()
{
    int n, h, i, j;
    char a;
    cin >> n;
    while (n--)
    {
        cin >> a >> h;
        for (i = 0; i < h / 6 + 1; i++)
            printf(" ");
        for (i = 0; i < (h - 2) / 2; i++)
            printf("%c", a);
        cout << endl;
        for (j = 0; j < (h - 3) / 2; j++)
        {
            for (i = 0; i < h / 6 + 1; i++)
                printf("%c", a);
            for (i = 0; i < (h - 2) / 2; i++)
                printf(" ");
            for (i = 0; i < h / 6 + 1; i++)
                printf("%c", a);
            cout << endl;
        }
        for (i = 0; i < h / 6 + 1; i++)
            printf(" ");
        for (i = 0; i < (h - 2) / 2; i++)
            printf("%c", a);
        cout << endl;
        for (j = 0; j < (h - 2) / 2; j++)
        {
            for (i = 0; i < h / 6 + 1; i++)
                printf("%c", a);
            for (i = 0; i < (h - 2) / 2; i++)
                printf(" ");
            for (i = 0; i < h / 6 + 1; i++)
                printf("%c", a);
            cout << endl;
        }
        for (i = 0; i < h / 6 + 1; i++)
            printf(" ");
        for (i = 0; i < (h - 2) / 2; i++)
            printf("%c", a);
        cout << endl;
        if (n)
            cout << endl;
    }
    return 0;
}