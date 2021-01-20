#include <stdio.h>
#include <stdlib.h> 

void output(int c,int b);
int minp(int c,int b);
int a[10][10];

int main()
{
	int r,i,j,k,m,m1,m2,max,hang,lie;
	printf("请输入行数和列数:\n");
	scanf("%d %d",&hang,&lie);
	printf("输入矩阵:\n"); 
	for(i=0;i<hang;i++)
	{
		for(j=0;j<lie;j++)
			scanf("%d",&a[i][j]);
	}
	for(k=0;k<hang;k++)
	{
		for(i=1+k;i<hang;i++)
		{
			if(a[i][k]!=0&&a[k][k]!=0)
			{
				m=minp(a[k][k],a[i][k]);
				m1=(m)/(a[i][k]);
				m2=(m)/(a[k][k]);
				for(j=k;j<lie;j++)
					a[i][j]=m1*a[i][j]-m2*a[k][j];
			}
			else if(a[k][k]==0)
			{
				int temp,h=k;
				for(int x=k+1;x<hang;x++)
				{
					if(a[x][k]!=0)
					{
						h=x;
						break;
					}
				}
				if(h!=k)
				{
					for(int x=0;x<lie;x++)
					{
						temp=a[k][x];
						a[k][x]=a[h][x];
						a[h][x]=temp;
					}
					i--;
				}
			}
		}
	}
	for(k=hang-1;k>0;k--)
	{
		for(i=k-1;i>=0;i--)
		{
			if(a[i][k]!=0&&a[k][k]!=0)
			{
				m=minp(a[k][k],a[i][k]);
				m1=(m)/(a[i][k]);
				m2=(m)/(a[k][k]);
				for(j=k;j>=0;j--)
					a[i][j]=m1*a[i][j]-m2*a[k][j];
			}
			else if(a[k][k]==0)
			{
				int temp,h=k;
				for(int x=k-1;x>=0;x--)
				{
					if(a[x][k]!=0)
					{
						h=x;
						break;
					}
				}
			}
		}
	}
	output(hang,lie);
	system("pause");
	return 0;
}

int minp(int c,int b)															//计算两个数的最小公倍数 
{
	int i;
	if(c>0&&b>0)
		i=c>b?c:b;
	else if(c>0&&b<0)
		i=c>(-b)?c:(-b);
	else if(c<0&&b>0)
		i=(-c)>b?(-c):b;
	else
		i=(-c)>(-b)?(-c):(-b);
	if(i%c==0&&i%b==0)
		return i;
	else
		i++;
}

/*int maxp(int a[][10],int k)
{
	int max=2,i;
	while(1)
	{
		for(i=0;i<5;i++)
		{
			if(a[k][i]%max==0)
				return max;
		}
		max++;
	}
}*/

void output(int c,int b)															//输出数组 
{
	int i,j;
	for(i=0;i<c;i++)
	{
		for(j=0;j<b;j++)
			printf("%4d",a[i][j]);
		printf("\n"); 
	}
	printf("\n");
}
