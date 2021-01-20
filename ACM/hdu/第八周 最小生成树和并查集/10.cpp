/*#include <cstdio>
#include <algorithm>
#define MAX 101
struct edge{
	int from,to,cost,con;
}BIN[MAX];

int N;
int father[MAX];

void init(){
	for(int i=1;i<=N;i++)
	father[i]=i;
}

bool cmp1(edge x,edge y){
	return x.con<y.con;
}

bool cmp2(edge x,edge y){
	return x.cost<y.cost;
}

int findx(int x){
	if(father[x]==x)	return x;
	return father[x]=findx(father[x]);
}
bool same(int x,int y){
	return findx(x)==findx(y);
}

void merge(int x,int y){
	int a=findx(x),b=findx(y);
	if(a==b)	return;
	father[a]=b;
}

int kr(){
	int res=0,temp=0,j=1;
	std::sort(BIN+1,BIN+1+N*(N-1)/2,cmp1);
	while(BIN[j].con==0){
		temp++;
		j++;
	}
	std::sort(BIN+1,BIN+1+temp,cmp2);
	for(int i=1;i<=N*(N-1)/2;i++){
		if(same(BIN[i].from,BIN[i].to))	continue;
		merge(BIN[i].from,BIN[i].to);
		if(BIN[i].con==1)	res+=0;
		else	res+=BIN[i].cost;
	}
	return res;
}

int main(){
	while(scanf("%d",&N)&&N!=0){
		init();
		for(int i=1;i<=N*(N-1)/2;i++)
			scanf("%d%d%d%d",&BIN[i].from,&BIN[i].to,&BIN[i].cost,&BIN[i].con);
		int res=kr();
		printf("%d\n",res);
	}
	return 0;
}*/
/*#include<stdio.h>
#include<queue>
using namespace std;
int n, sum;
int vis[101];
struct node {
    int x, y, len;
    
    node(int temp, int temp1, int temp2) {
        x = temp;
        y = temp1;
        len = temp2;
    }
    friend bool operator < (const node& temp, const node& temp1) {
        return temp.len > temp1.len;
    }
};
int find(int temp) {
    if (vis[temp] == temp)
        return temp;
    return find(vis[temp]);
}
void marge(int temp, int temp1) {
    int first = find(temp);
    int first1 = find(temp1);
    vis[first1] = first;
}
int main()
{
    while (scanf("%d", &n) != EOF&&n) {
        priority_queue<node> q;
        int m = (n*(n - 1)) / 2;
        for (int i = 1; i <= n; i++) {
            vis[i] = i;
        }
        int num = n;
        sum = 0;
        while (m--) {
            int temp, temp1, temp2, temp3;
            scanf("%d%d%d%d", &temp, &temp1, &temp2, &temp3);
            if (temp3 == 1) {
                marge(temp, temp1);
                num--;
            }
            else {
                node b(temp, temp1, temp2);
                q.push(b);
            }
        }
        while (num != 1) {
            int x = q.top().x;
            int y = q.top().y;
            int len = q.top().len;
            if (find(x) != find(y)) {
                marge(x, y);
                num--;
                sum += len;
            }
            q.pop();
        }
        printf("%d\n", sum);
    }
    return 0;
}*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, sum, index1;
int vis[101];
struct road {
	int begin;
	int end;
	int cost;
	int status;
}a[10000];
bool cmp(road x, road y) {
	if (x.status > y.status)
		return true;
	else if (x.status == y.status)
		return x.cost < y.cost;
	else
		return false;
}
bool ha(int temp, int temp1) {
	bool d = false;
	if (vis[temp] == 0 && vis[temp1] != 0) {
		vis[temp] = vis[temp1];
		d = true;
	}
	else if (vis[temp] != 0 && vis[temp1] == 0) {
		vis[temp1] = vis[temp];
		d = true;
	}
	else if (vis[temp] != vis[temp1] && vis[temp1] != 0 && vis[temp] != 0) {
		int min = (vis[temp] > vis[temp1]) ? vis[temp1] : vis[temp];
		int max = (vis[temp] > vis[temp1]) ? vis[temp] : vis[temp1];
		for (int i = 1; i <= n; i++) {
			if (vis[i] == max)
				vis[i] = min;
		}
		d = true;
	}
	else if (vis[temp] == 0 && vis[temp1] == 0) {
		vis[temp] = vis[temp1] = index1;
		index1++;
		d = true;
	}
	return d;
}
bool haha() {
	bool d = true;
	for (int i = 1; i <= n; i++) {
		if (vis[i] != 1) {
			d = false;
			break;
		}
	}
	return d;
}
int main()
{
	while (scanf("%d", &n) != EOF&&n) {
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		sum = 0;
		int num = (n*(n - 1)) / 2;
		index1 = 1;
		for(int i=0;i<num;i++){
			int temp, temp1, temp2, temp3;
			scanf("%d%d%d%d", &temp, &temp1, &temp2, &temp3);
			road h;
			h.begin = temp;
			h.end = temp1;
			h.cost = temp2;
			h.status = temp3;
			a[i] = h;
		}
		sort(a, a + num, cmp);
		for (int i = 0; i < num; i++) {
			if (haha())
				break;
			if (a[i].status == 1) {
				ha(a[i].begin, a[i].end);
			}
			else {
				if (ha(a[i].begin, a[i].end))
					sum += a[i].cost;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
