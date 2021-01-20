#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000] = { 0 }, b[20] = { 0 }, c[10][10] = { 0 };
    int lena = 0, lenb = 0, s[20] = { -1 }, col = 0, m, n, z;
    printf("输入句子:");
    gets(a);
    printf("输入字符串:");
    gets(b);
    lena = strlen(a);
    lenb = strlen(b);
    for (int i = 0; i < lena; i++)//以a[i]为起点，逐位向后比较 
    {
        int k = i, p = 0;
        for (int j = i; (j - i) < lenb; j++)
        {						  //以a[i]与b[j-i]比较，在b长度范围内遇到不同字符跳出循环 
            k = j;
            if (b[j - i] == a[j])
                p = 1;
            else
            {
                p = 0; 
                k = i; 
                break;
            }
        }
        if (p == 1)
        {
            for (m = k; ((a[m] >= 'A' && a[m] <= 'Z') || (a[m] >= 'a' && a[m] <= 'z')) && m <= lena; m++);//确定单词尾巴的序号 
            for (n = k; ((a[n] >= 'A' && a[n] <= 'Z') || (a[n] >= 'a' && a[n] <= 'z')) && n >= 0; n--);//确定单词头的序号 
            z = 0;
            for (int j = n + 1; j <= m - 1; j++, z++)
                c[col][z] = a[j];
            col++;
            i = m - 1;
        }
    }
    z = 0;
    for (int i = 0; i < col; i++)//比较筛选出的单词中有没有重复的，若有，记下其序号 
    {
        for (int j = i + 1; j < col; j++)
        {
            if (strcmp(c[i], c[j]) == 0)
            {
                s[z] = i; z++;
            }
        }
    }
    z = 0;
    for (int i = 0; i < col; i++)//输出单词 
    {
        if (i != s[z])
            printf("%s\n", c[i]);
        else
            z++;
    }
    return 0;
}
