#include <stdio.h>
int main()
{
    int a,b,c=1,d;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a<b)
        {
            d=a;
            a=b;
            b=d;
        }
        for(c=a;c>0;c++)
        {
            if(c%a==0&&c%b==0)
            {
                printf("%d\n",c);
                break;
            }
        }
    }
    return 0; 
} 
