#include <stdio.h>
int bin[1002];
int findx(int x)
{
	int r=x;
	while(bin[r]!=r)
		r=bin[r];
	return r;
}
void merge(int x,int y)
{
	int fx,fy;
	fx=findx(x);
	fy=findx(y);
	if(fx!=fy)
		bin[fx]=fy;
}
int main()
{
	int t,m,n,x,y,i,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			bin[i]=i;
		}
		for(scanf("%d",&m);m>0;m--)
		{
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		for(count=0,i=1;i<=n;i++)
		{
			if(bin[i]==i)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
