#include <cstdio>
#include <algorithm>
#define MAX 502
using namespace std;

struct edge{
	int from,to,cost;
}BIN[MAX*MAX];

int M,N,K,cou;
int father[MAX];

void init(){
	for(int i=1;i<=N;i++)
		father[i]=i;
}

int findx(int x){
	if(father[x]==x)	return x;
	return father[x]=findx(father[x]);
}

bool same(int a,int b){
	return findx(a)==findx(b); 
}

bool merge(int x,int y){
	int a=findx(x),b=findx(y);
	if(a==b)	return false;
	father[a]=b;
	return true;
}

bool cmp(edge a,edge b){
	return a.cost<b.cost;
}

int kr(){
	int res=0;
	sort(BIN+1,BIN+1+M,cmp);
	for(int i=1;cou<N-1&&i<=M;i++){
		if(merge(BIN[i].from,BIN[i].to)){
			res+=BIN[i].cost;
			cou++;
		}
	}
	return res;
}

int main(){
	int t,x,a,b;
	scanf("%d",&t);
	while(t--){
		int j=1;
		cou=0;
		scanf("%d%d%d",&N,&M,&K);
		init();
		for(int i=1;i<=M;i++)
			scanf("%d%d%d",&BIN[i].from,&BIN[i].to,&BIN[i].cost);
		for(int i=1;i<=K;i++){
			scanf("%d%d",&x,&a);
			for(j=1;j<x;j++){
				scanf("%d",&b);
				if(merge(a,b))	cou++;
			}
		}
		int res=kr();
		if(cou!=N-1)	printf("-1\n");
		else	printf("%d\n",res);
	}
	return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

struct Road
{
	int distance;
	int a;
	int b;
}r[25000];

int p[501];
int find_set (int x);
int union_set (int a, int b);
int cmp (const void *a, const void *b);

int main()
{
	int T;
	int N, M, K;
	int count, len;
	int i, j;
	int number, a, b;
	scanf ("%d", &T);
	while (T --)
	{
		scanf ("%d%d%d", &N, &M, &K);
		for (i = 0; i < M; i ++)
			scanf ("%d%d%d", &r[i].a , &r[i].b, &r[i].distance);
		for (i = 1; i <= N; i ++)												//void init();
			p[i] = i;
		count = 0;
		for (i = 0; i < K; i ++){
			scanf ("%d%d", &number, &a);
			for (j = 1; j < number; j ++){
				scanf ("%d", &b);
				if (union_set (a, b))	count ++;
			}
		}
		len = 0;
		qsort (r, M, sizeof (Road), cmp);
		for (i = 0; count < N - 1 && i < M; i ++){
			if (union_set (r[i].a, r[i].b)){
				count ++;
				len += r[i].distance;
			}
		}
		if (count != N - 1)	printf ("-1\n");
		else	printf ("%d\n", len);
	}
	return 0;
}

int find_set (int x)
{
	if (p[x] != x)
	{
		p[x] = find_set (p[x]);
	}
	return p[x];
}
int union_set (int a, int b)
{
	int pa= find_set (a), pb = find_set (b);
	if (pa != pb){
		p[pb] = pa;
		return 1;
	}
	return 0;
}

int cmp (const void *a, const void *b)
{
	Road *v1 = (Road *)a;
	Road *v2 = (Road *)b;
	return v1->distance - v2->distance;
}*/
