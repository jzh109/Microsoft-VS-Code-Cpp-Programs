#include <cstdio>
#include <algorithm>
#include <math.h>
#define MAX 101
using namespace std;

struct picture{
	float x,y;
}pic[MAX];

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
	while(scanf("%d",&N)!=EOF){
		int temp=1;
		init();
		for(int i=1;i<=N;i++)
			scanf("%f%f",&pic[i].x,&pic[i].y);
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
	return 0;
}
