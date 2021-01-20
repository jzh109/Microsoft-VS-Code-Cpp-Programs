#include <stdio.h>
#include <math.h>

int sishewuru(float a);
int main()
{
	int n=450;
	float a[500],b[500];
	int i,j;
	a[0]=0;
	b[0]=0;
	for(i=1;i<n;i++)
	{
		a[i]=a[i-1]+0.01;
		b[i]=cos(a[i]);
	}
	int A[500],B[500];
	for(i=0;i<n;i++)
	{
		printf("sin(%f)=%f\n",a[i],b[i]);
		a[i]=100*a[i];
		b[i]=55*b[i];
		A[i]=sishewuru(a[i]);
		B[i]=sishewuru(b[i])+60;
		printf("sin(%d)=%d\n",A[i],B[i]);
	}
	for(i=100;i>=0;i--);
	{
		for(j=0;j<n;j++);
		{
			if(i==B[j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
} 
int sishewuru(float a)
{
 	int m;
 	if(a-floor(a)<0.5)
 	{
 		m=a;
 		return m;
	}
	else
	{
	 	m=a+1;
	 	return m;
	}
}
