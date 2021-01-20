/*#include <stdio.h>
int bin[1000];
int findx(int x)
{
	if(bin[x]==x)	return x;
	return bin[x]=findx(bin[x]);
}
void merge(int x,int y)
{
	int fx=findx(x),fy=findx(y);
	if(fx!=fy)
		bin[fx]=fy;
}
int main()
{
	int n,m,count,x,y,i;
	while(scanf("%d",&n)&&n!=0)
	{
		for(i=1;i<=n;i++)
		{
			bin[i]=i;
		}
		for(scanf("%d",&m);m>0;m--)
		{
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		for(count=-1,i=1;i<=n;i++)
		{
			if(bin[i]==i)
				count++;				
		}
		printf("%d\n",count);
	}
	return 0;
}*/
#include <cstdio>
#define MAX 1001
struct edge{
	int x,y;
}BIN[MAX*MAX];
int N,M;
int father[MAX];
void init(){
	for(int i=1;i<=N;i++)
		father[i]=i;
}
int findx(int x){
	if(father[x]==x)	return x;
	return father[x]=findx(father[x]);
}
void merge(int x,int y){
	int a=findx(x),b=findx(y);
	if(a==b)	return;
	father[a]=b; 
}
int main(){
	while(scanf("%d",&N)==1&&N!=0){
		scanf("%d",&M);
		init();
		for(int i=1;i<=M;i++){
			scanf("%d%d",&BIN[i].x,&BIN[i].y);
			merge(BIN[i].x,BIN[i].y);
		} 
		int count=0;
		for(int i=1;i<=N;i++)
			if(father[i]==i)	
				count++;
		printf("%d\n",count-1);
	}
	return 0;
}

