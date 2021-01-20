#include <cstdio>
#include <algorithm>
#define MAX 103

struct edge{
	int from,to,len;
}BIN[MAX*(MAX-1)/2];

int father[MAX];
int N,M;

#define M (N-1)*N/2

void init(){
	for(int i=1;i<=M;i++)
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

bool cmp(edge x,edge y){
	return x.len<y.len;
}

int kr(){
	int res=0;
	std::sort(BIN+1,BIN+1+M,cmp);
	for(int i=1;i<=M;i++){
		if(findx(BIN[i].from)==findx(BIN[i].to))	continue;
		merge(BIN[i].from,BIN[i].to);
		res+=BIN[i].len;
	}
	return res;
}

int main(){
	int res;
	while(scanf("%d",&N)!=EOF){
		if(N==0)	break;
		init();
		for(int i=1;i<=M;i++)
			scanf("%d%d%d",&BIN[i].from,&BIN[i].to,&BIN[i].len);
		res=kr();
		printf("%d\n",res);
	}
	return 0;
}

/*#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,pre[10000];
struct node
{
    int a,b,val;
}p[10000];
int cmp(node x,node y)
{
    return x.val<y.val;
}
int find(int x)
{
    if(x==pre[x])
        return x;
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    int i=x,j;
    while(i!=j)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    pre[find(x)]=find(y);
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        m=n*(n-1)/2;
        for(int i=0;i<=m;i++) pre[i]=i;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].val);
        sort(p+1,p+m+1,cmp);
        int ant=0;
        for(int i=1;i<=m;i++)
        {
            if(find(p[i].a) != find(p[i].b) )
            {
                ant+=p[i].val;
                join(p[i].a,p[i].b);
            }
        }
        printf("%d\n",ant);
    }
    return 0;
}*/
/*#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct Edge {
    int a,b;
    int value;
} edge[5000];

int Tree[105];

int findRoot(int x) {
    if(Tree[x]==-1) {
        return x;
    } else {
        int tmp=findRoot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}

bool cmp(Edge e1,Edge e2) {
    return e1.value<e2.value;
}

int main() {
    int n;
    while(1) {
        scanf("%d",&n);
        if(n==0) {
            break;
        } else {
            //初始化
            for(int i=1; i<=n; i++) {
                Tree[i]=-1;
            }
            //输入
            for(int i=1; i<=n*(n-1)/2; i++) {
                scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].value);
            }
            //从小到大排序
            sort(edge+1,edge+1+n*(n-1)/2,cmp);
            int a,b;
            int ans=0;    
            for(int i=1; i<=n*(n-1)/2; i++) {
                a=findRoot(edge[i].a);
                b=findRoot(edge[i].b);
                if(a!=b) {
                    Tree[a]=b;
                    ans+=edge[i].value; 
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}*/
