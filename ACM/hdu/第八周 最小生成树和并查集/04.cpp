#include <cstdio>
#include <algorithm>
#define MAX 10000001

struct edge{																	//create structure 
	int a,b;
}BIN[MAX];

int father[MAX];
int N,M=0;

void init(){																	//initial forest
	for(int i=1;i<=M;i++)
		father[i]=i;
} 

int findx(int x){																//locate THE tree
	if(father[x]==x) return x;
	return father[x]=findx(father[x]);
}

void merge(int x,int y){														//merge data
	int a=findx(x),b=findx(y);
	if(a==b) return;
	father[a]=b;
}

int main(){
	while(scanf("%d",&N)!=EOF){
		for(int i=1;i<=N;i++){
			scanf("%d%d",&BIN[i].a,&BIN[i].b);
			if(M<BIN[i].a)	M=BIN[i].a;
			if(M<BIN[i].b)	M=BIN[i].b;
		}
		init();
		for(int i=1;i<=N;i++)
			merge(BIN[i].a,BIN[i].b);
		for(int i=1;i<=N;i++)
			merge(BIN[i].a,BIN[i].b);
		std::sort(father+1,father+1+M);
		int temp=0,max=0;
		if(M==1)	printf("1\n");
		else{
			for(int i=1;i<=M;i++){
				if(father[i]==father[i+1])	temp++;
				else{
					temp++;
					if(max<temp)	max=temp;
					temp=0;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
