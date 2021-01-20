#include <bits/stdc++.h>
using namespace std;

struct Node{
	int x,y,z;
	double dis;
	bool operator <(Node other)const{
		return dis<other.dis;
	}
}node[1005];

int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++) {
			cin>>node[i].x>>node[i].y>>node[i].z;
			node[i].dis = sqrt(node[i].x*node[i].x+node[i].y*node[i].y+node[i].z*node[i].z);
		}
		sort(node,node+n);
		printf("%.3f\n",node[0].dis);
	}
	return 0;
}
