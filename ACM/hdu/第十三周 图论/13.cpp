#include <bits/stdc++.h>
#define MAX 1000000
#define M N*(N-1)/2

struct edge{
	int from,to,dis;
}BIN[MAX];

int N;
int father[MAX];

void init(){
	for(int i = 1; i <= N; i++)
		father[i] = i;
}

bool cmp(edge a,edge b){
	return a.dis < b.dis;
}

int findx(int x){
	if(father[x] == x)    return x;
	return father[x] = findx(father[x]);
}

void merge(int x,int y){
	int a = findx(x), b = findx(y);
	if(a == b)  return;
	father[a] = b;
}

int krus(){
	int res = 0;
	std::sort(BIN + 1,BIN + 1 + M,cmp);
	for(int i = 1; i <= M; i++){
		if(findx(BIN[i].from) == findx(BIN[i].to))    continue;
		merge(BIN[i].from, BIN[i].to);
		res += BIN[i].dis;
	}
	return res;
}

int main(){
	while(scanf("%d", &N) != EOF && N){
		init();
		for(int i = 1; i <= M; i++)
			scanf("%d%d%d", &BIN[i].from, &BIN[i].to, &BIN[i].dis);
		int res = krus();
		printf("%d\n",res);
	}
	return 0;
}
