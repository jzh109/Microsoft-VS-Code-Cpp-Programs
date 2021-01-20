#include <stdio.h>
int main()
{
	int *p,a[10]={9,5,6,7,8,4,2,1,3,0},i,j,temp;
	p=&a[0];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(*(p+j)>*(p+j+1))
			{ 
				temp=*(p+j+1);
				*(p+j+1)=*(p+j);
				*(p+j)=temp;
			}
		}
	}
	for(i=0;i<10;i++)
		printf("%d",*(p+i));
}
