#include <cstdio>
#include <algorithm>
#include <math.h>
#define MAX 102
using namespace std;

int father[MAX];
int N,M;
bool judge;

struct island{
	int x,y;
}is[MAX];

struct edge{
	int x,y;
	float len;
}dis[MAX*MAX];

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

float Pythagoras(int a,int b){
	return sqrt(a*a+b*b);
}

bool cmp(edge a,edge b){
	return a.len<b.len;
}

float kr(){
	float res=0;
	sort(dis+1,dis+1+N*N,cmp);
	for(int i=1;i<=N*N;i++){
		if(dis[i].len==0)	continue;
		if(findx(dis[i].x)==findx(dis[i].y))	continue;
		merge(dis[i].x,dis[i].y);
		res+=dis[i].len;
		M=father[i];
	}
	return res;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		judge=true;
		scanf("%d",&N);
		init();
		for(int i=1;i<=N;i++)
			scanf("%d%d",&is[i].x,&is[i].y);
		int cot=1;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				dis[cot].len=Pythagoras(is[i].x-is[j].x,is[i].y-is[j].y);
				dis[cot].x=i;
				dis[cot].y=j;
				/*if(dis[cot].len<=10||dis[cot].len>=1000){
					if(i!=j)	judge=false;
					break;
				}*/
				cot++;
			}
			//if(judge==false)	break;
		}
		float res=kr();
		for(int i=1;i<=N*N;i++){
			if(father[i]==father[M]&&(dis[i].len<=10||dis[i].len>=1000)){
				judge=false;
				break;
			}
		}
		printf("%.1f\n",res*100);
	}
	return 0;
}
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MaxSize 105
struct islands{
	int num;//计点的编号
	int x, y;
}island[MaxSize];
struct distances {
	struct islands start, end;
	double dis;
}dis[MaxSize*MaxSize];
int Contain[MaxSize];
void Initialize(int N) {
	for (int i = 0; i <= N; i++) {
		Contain[i] = i;
	}
}
int Findhead(int N) {
	if (N != Contain[N]) {
		Contain[N] = Findhead(Contain[N]);
	}
	return Contain[N];
}
void Merge(int A, int B) {
	int FindA = Findhead(A);
	int FindB = Findhead(B);

	if (FindA != FindB) {
		Contain[FindA] = Contain[FindB];
	}
}
double Distance(islands a, islands b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool cmp (distances a, distances b) {
	return a.dis < b.dis;
}
int main() {
	int T;//计案例数
	int C;//输入点数

	while (scanf("%d", &T) == 1) {
		for (int i = 0; i < T; i++) {

			scanf("%d", &C);
			for (int j = 0; j < C; j++) {//用结构体储存坐标
				scanf("%d%d", &island[j].x, &island[j].y);
				island[j].num = j + 1;
			}

			int count = 0;
			for (int j = 0; j < C; j++) {//计算出每一点到其他点的距离
				for (int k = j + 1; k < C; k++) {
					dis[count].start = island[j];
					dis[count].end = island[k];
					dis[count].dis = Distance(island[j], island[k]);
					count++;
				}
			}

			Initialize(C);//初始化
			sort(dis, dis + count, cmp);//按距离的大小排序

			int NumSide = 0;//计边数
			double Length = 0;//计长度
			for (int j = 0; j < count; j++) {
				if (Findhead(dis[j].start.num) != Findhead(dis[j].end.num) ){
					if (dis[j].dis >= 10 && dis[j].dis <= 1000) {
						Merge(dis[j].start.num, dis[j].end.num);
						NumSide++;
						Length += dis[j].dis;
					}
				}
			}
			//输出判定
			if (NumSide + 1 != C)
				printf("oh!\n");
			else {
				printf("%.1f\n", Length * 100);
			}

		}
	}
	return 0;
}
