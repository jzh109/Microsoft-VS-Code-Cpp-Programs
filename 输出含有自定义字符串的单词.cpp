#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000] = { 0 }, b[20] = { 0 }, c[10][10] = { 0 };
    int lena = 0, lenb = 0, s[20] = { -1 }, col = 0, m, n, z;
    printf("�������:");
    gets(a);
    printf("�����ַ���:");
    gets(b);
    lena = strlen(a);
    lenb = strlen(b);
    for (int i = 0; i < lena; i++)//��a[i]Ϊ��㣬��λ���Ƚ� 
    {
        int k = i, p = 0;
        for (int j = i; (j - i) < lenb; j++)
        {						  //��a[i]��b[j-i]�Ƚϣ���b���ȷ�Χ��������ͬ�ַ�����ѭ�� 
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
            for (m = k; ((a[m] >= 'A' && a[m] <= 'Z') || (a[m] >= 'a' && a[m] <= 'z')) && m <= lena; m++);//ȷ������β�͵���� 
            for (n = k; ((a[n] >= 'A' && a[n] <= 'Z') || (a[n] >= 'a' && a[n] <= 'z')) && n >= 0; n--);//ȷ������ͷ����� 
            z = 0;
            for (int j = n + 1; j <= m - 1; j++, z++)
                c[col][z] = a[j];
            col++;
            i = m - 1;
        }
    }
    z = 0;
    for (int i = 0; i < col; i++)//�Ƚ�ɸѡ���ĵ�������û���ظ��ģ����У���������� 
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
    for (int i = 0; i < col; i++)//������� 
    {
        if (i != s[z])
            printf("%s\n", c[i]);
        else
            z++;
    }
    return 0;
}
