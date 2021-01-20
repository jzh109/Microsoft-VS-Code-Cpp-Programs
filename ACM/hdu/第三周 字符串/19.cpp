#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char str[1000];
    int len,i;
    while(gets(str))
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]>=65&&str[i]<=90)
                str[i]=str[i]+32;
        }
        puts(str);
    }
    return 0;
}
