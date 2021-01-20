#include <cstdio>                                           //WA
#include <algorithm>
#include <string.h>
#define MAX 1200000

struct edge{
	char a,b;
}BIN[MAX];

int father[MAX],vis[MAX];
int N,M;

void init(){
	for(int i=0;i<N;i++)
		father[i]=i+N;
	for(int i=N;i<N*2+1+M;i++)
		father[i]=i;
}

int findx(int x){
	if(father[x]==x)    return x;
	return father[x]=findx(father[x]);
}

void merge(int x,int y){
	int a=findx(x),b=findx(y);
	if(a==b)    return;
	father[a]=b;
}

int main(){
	char temp,o=1;
	int s;
	while(~scanf("%d%d",&N,&M)){
		if(N==0&&M==0)  break;
		int cont=N*2;
		init();
		for(int i=1;i<=M;i++){
			getchar();
			scanf("%c",&temp);
			if(temp=='M'){
				scanf("%d%d",&BIN[i].a,&BIN[i].b);
				merge(BIN[i].a,BIN[i].b);
			}
			else if(temp=='S'){
				scanf("%d",&s);
				father[s]=cont++;
			}
		}
		//int test=-1,cou=0;
		/*for(int i=1;i<=N;i++){
			if(father[i]!=test){
				test=father[i];
				cou++;
			}
			else    continue;
		}*/
		int output=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<N;i++)
        {
            int tmp=findx(i);
            if(vis[tmp]==0)
            {
                vis[tmp]=1;
                output++;
            }
        }
		printf("Case #%d: ",o++);
		printf("%d\n",output);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
using namespace std;
int vis[1200000];
int f[1200000];
int find(int a)
{
    int r=a;
    while(f[r]!=r)
    r=f[r];
    int i=a;
    int j;
    while(i!=r)
    {
        j=f[i];
        f[i]=r;
        i=j;
    }
    return r;
}
void merge(int a,int b)
{
    int A,B;
    A=find(a);
    B=find(b);
    if(A!=B)
    f[B]=A;
}
int main()
{
    int n,m;
    int kase=0;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        int cont=n*2;
        for(int i=0;i<n;i++)
        {
            f[i]=i+n;
        }
        for(int i=n;i<2*n+m+1;i++)
        {
            f[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            char op[5];
            scanf("%s",op);
            if(op[0]=='M')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                merge(x,y);
            }
            if(op[0]=='S')
            {
                int x;
                scanf("%d",&x);
                f[x]=cont++;
            }
        }
        int output=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            int tmp=find(i);
            if(vis[tmp]==0)
            {
                vis[tmp]=1;
                output++;
            }
        }
        printf("Case #%d: %d\n",++kase,output);
    }
}
