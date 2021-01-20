#include<cstdio>
#include<algorithm>
#define MAX_SPEED 10000000

int N;
int parent[3000];

struct edge{
    int u,v,speed;
}BIN[3000];

bool cmp(edge s1,edge s2){
    return s1.speed<s2.speed;
}

int findx(int x){
    if(x!=parent[x]) parent[x]=findx(parent[x]);
    else return x;
}

void merge(int x,int y){
    int i=findx(x),j=findx(y);
    if(i!=j)	parent[i]=j;
}
void init(){
    for(int i=1;i<=N;i++)
        parent[i]=i;
}

int main(){
    int i,j,m,t,from,to,res,most,small;
    while(scanf("%d%d",&N,&m)!=EOF){
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&BIN[i].u,&BIN[i].v,&BIN[i].speed);
        std::sort(BIN+1,BIN+m+1,cmp);
        scanf("%d",&t);
        while(t--){
            scanf("%d%d",&from,&to);
            res=MAX_SPEED;
            for(i=1; i<=m; i++){
                init();
                small=BIN[i].speed;
                int flag=0;
                for(j=i; j<=m; j++){
                    merge(BIN[j].u,BIN[j].v);
                    most=BIN[j].speed;
                    if(findx(from)==findx(to)){
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    if((most-small)<res) res=most-small;
            }
            if(res==MAX_SPEED)	printf("-1\n");
            else printf("%d\n",res);
        }
    }
    return 0;
}
