/*#include<iostream>
#include<set>
std::set<int> Node;
int main(void)
{
	int a, b,i=1;
	scanf("%d%d",&a,&b);
	while (a!=-1&&b!=-1)
	{
		Node.clear();
		int cnt = 0;
		while (a!=0||b!=0)
		{
			Node.insert(a); Node.insert(b);
			scanf("%d%d",&a,&b);
		}
		if (Node.size() == 0 && cnt == 0)
		{
			printf("Case %d is a tree.\n",i);
		}
		else if (Node.size() == 1 && cnt == 1)
		{
			printf("Case %d is not a tree.\n",i);
		}
		else if (Node.size() == cnt + 1)
			printf("Case %d is a tree.\n",i);
		else printf("Case %d is a not tree.\n",i);
		i++;
		scanf("%d%d",&a,&b);
	}
}*///TLE


#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn = 1e5 + 1;
int fa[Maxn];

int getfa(int n) {
	if (fa[n] == 0) return fa[n] = n;
	if (fa[n] != n) return fa[n] = getfa(fa[n]);
	else return n;
}

int main() 
{
	int x, y;
	int T = 0;
	while (scanf("%d%d", &x, &y) != EOF&&x>=0) {
		int flag = 1;
		memset(fa, 0, sizeof(fa));
		if (x == 0 && y == 0) {
			printf("Case %d is a tree.\n",++T);
			continue;
		}
		x = getfa(x);
		y = getfa(y);
		if (x != y) {
			fa[y] = x;
		}
		else {
			flag = 0;
		}
		while (scanf("%d%d", &x, &y) != EOF&&x) {
			if (getfa(y) != y) { flag = 0; }
			else {
				x = getfa(x);
				y = getfa(y);
				if (x != y) {
					fa[y] = x;
				}
				else {
					flag = 0;
				}
			}
		}
		int cnt=0;
		for (int i = 1; i < Maxn; i++) {
			if (fa[i] > 0 &&fa[i]==i) {				
				cnt++;
			}
		}
		if (cnt > 1)flag = 0;
		if (flag)printf("Case %d is a tree.\n",++T);
		else printf("Case %d is not a tree.\n", ++T);
	}
}
