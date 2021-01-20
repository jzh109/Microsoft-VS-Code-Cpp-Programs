#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    char str1[100], str2[100];
    cin.getline(str1, 100);
    cin.getline(str2, 100);
    int i, j, k;
    for (k = 0; str2[k] != '#'; k++)
        ;
    str2[k] = 0;
    for (i = 0; str1[i] != '#'; i++)
        ;
    str1[i] = 0;
    if (i == 0 || k == 0)
    {
        puts(str1);
        return 0;
    }
    for (j = 0; j < i; j++)
    {
        str2[j + k] = str1[j];
    }
    str2[j + i] = 0;
    puts(str2);
    return 0;
}