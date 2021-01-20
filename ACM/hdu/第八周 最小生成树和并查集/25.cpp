#include <cstdio>
#include <algorithm>
#include <string.h>

struct node{
	int u,v;
	int w;
	void input(){
		scanf("%d%d%d",&u,&v,&w);
	}
}edge[201000];

int f[20000];
int h[20000];

void init(){
	for(int i=0;i<11100;i++)
		f[i]=i;
}
 
int getf(int v){									//int findx(int x)
	if(f[v]!=v)
	f[v]=getf(f[v]);
	return f[v];
}
 
void merge(int u,int v){
	int t1=getf(u);
	int t2=getf(v);
	if(t2!=t1){
		f[t2]=t1;
	}
}

bool cmp(node a,node b){
	return a.w>b.w;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m),n+m){
		init();
		memset(h,0,sizeof(h));
		for(int i=0;i<m;i++)
			edge[i].input();
		std::sort(edge,edge+m,cmp);
		int ans=0,flag=1;
		for(int i=0;i<m;i++){
			if(getf(edge[i].u)!=getf(edge[i].v)){
				if(h[getf(edge[i].u)]+h[getf(edge[i].v)]<=1){
					ans+=edge[i].w;
					int tem=h[getf(edge[i].u)]+h[getf(edge[i].v)];//一开始少了这一句，两个集合合并时，要把环的数量也要一块合并 
					//应该先加环数，要不父节点就改变了，再加和求出的环数就不对了。 
					merge(edge[i].u,edge[i].v);
					h[getf(edge[i].u)]=tem;
				}
			}
			else{
				if(h[getf(edge[i].u)]==0){
					h[getf(edge[i].u)]=1;
					ans+=edge[i].w;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
