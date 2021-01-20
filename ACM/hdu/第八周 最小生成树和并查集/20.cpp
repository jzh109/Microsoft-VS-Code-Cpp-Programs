#include <cstdio>
#include <algorithm>
#include <math.h>
#define MAX 1010
using namespace std;

struct city_sys{
	int x,y,pop;
}city[MAX];

struct dis{
	int from,to;
	float len;
}len[MAX*MAX];

int N;
int father[MAX];

void init(){
	for(int i=1;i<=N;i++)
		father[i]=i;
}

bool cmp(dis a,dis b){
	return a.len<b.len;
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

float kr(){
	float res=0;
	sort(len+1,len+1+N*N,cmp);
	for(int i=1;i<=N*N;i++){
		if(len[i].from==len[i].to||findx(len[i].from)==findx(len[i].to))	continue;
		merge(len[i].from,len[i].to);
		res+=len[i].len;
	}
	return res;
}

float pyd(float x1,float x2,float y1,float y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		while(scanf("%d",&N)!=EOF){
			int temp=1;
			init();
			for(int i=1;i<=N;i++)
				scanf("%d%d%d",&city[i].x,&city[i].y,&city[i].pop);
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					len[temp].len=pyd(pic[i].x,pic[j].x,pic[i].y,pic[j].y);
					len[temp].from=i;
					len[temp].to=j;
					temp++;
				}
			}
			float res=kr();
			printf("%.2f\n",res);
		}
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxn 1003
#define inf 1000000000

int x[maxn], y[maxn], p[maxn];
double map[maxn][maxn];
double dis[maxn];
int pre[maxn];
int vis[maxn];
double mst;
double dp[maxn][maxn];
int n, m;
double ans;

double maxz(double a, double b)
{
    return a > b ? a : b;
}

double Dis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) * 1.0 + (y1 - y2) * (y1 - y2) * 1.0);
}

void prim()
{
    int i, j, k;
    memset(dp, 0, sizeof(dp));
    for(i = 1; i < n; i++)
    {
        dis[i] = map[0][i];
        vis[i] = 0;
        pre[i] = 0;
    }
    dis[0] = inf;
    vis[0] = 1;
    pre[0] = -1;
    mst = 0;
    for(i = 0; i < n-1; i++)
    {
        k = 0;
        for(j = 1; j < n; j++)
            if(!vis[j] && dis[k] > dis[j])
                k = j;
        vis[k] = 1;
        mst += dis[k];
        dp[pre[k]][k] = dp[k][pre[k]] = map[k][pre[k]];
        for(j = 1; j < n; j++)
            if(!vis[j] && dis[j] > map[k][j])
             {
                dis[j] = map[k][j];
                pre[j] = k;
              }
        for(j = 1; j < n; j++)
             if(vis[j] && j != k)
            {
                dp[j][k] = dp[k][j] = maxz(dp[j][pre[k]],dp[pre[k]][k]);
            }
    }
}

void solve()
{
    int i, j;
    double ans = 0,tmp;
    for(i = 0; i < n ;i++)
        for(j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            tmp = (p[i] + p[j]) * 1.0/ (mst - dp[i][j]);
            if(tmp > ans) ans = tmp;
        }
    printf("%.2f\n", ans);
}

main()
{
    int i, j, cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d%d%d", &x[i], &y[i], &p[i]);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(i != j)
                    map[i][j] = map[j][i] = Dis(x[i], y[i], x[j], y[j]);
        prim();
        solve();
    }
}
