#include <stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
       	for (j=n-i-1;j>0;j--)
       	    printf(" ");
       	for (j=0;j<2*i+1;j++)
            printf("%d",j+1);
        printf("\n");
    }
   	for (i=n-1;i>=0;i--)
    {
	    for (j=n-i;j>0;j--)
           	printf(" ");
       	for (j=0;j<2*i-1;j++)
       	    printf("%d",j+1);
        printf("\n");
	}
    return 0;
}
