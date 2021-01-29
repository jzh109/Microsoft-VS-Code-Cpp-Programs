#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        string st, s1 = "", s2 = "";
        getline(cin, st);
        int c1 = 0, c2 = 0;
        while (getline(cin, st) && st != "END")
        {
            s1 = s1 + st;
            c1++;
        }
        getline(cin, st);
        while (getline(cin, st) && st != "END")
        {
            s2 = s2 + st;
            c2++;
        }
        if (s1 == s2 && c1 == c2)
            printf("Accepted\n");
        else
        {
            string ss1 = "", ss2 = "";
            int i, len1 = s1.size(), len2 = s2.size();
            for (i = 0; i < len1; i++)
            {
                if (s1[i] != '\n' && s1[i] != ' ' && s1[i] != '\t')
                    ss1 += s1[i];
            }
            for (i = 0; i < len2; i++)
            {
                if (s2[i] != '\n' && s2[i] != ' ' && s2[i] != '\t')
                    ss2 += s2[i];
            }
            if (ss1 == ss2)
                printf("Presentation Error\n");
            else
                printf("Wrong Answer\n");
        }
    }
    return 0;
}