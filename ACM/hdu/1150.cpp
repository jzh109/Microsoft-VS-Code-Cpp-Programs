#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

int m,n,k;
bool used[MAX];
int maps[105][105],rightt[MAX];

bool findx(int x){
	for(int j=0;j<m;j++){
		if(maps[x][j]&&!used[j]){
			used[j]=true;
			if(!rightt[j]||findx(rightt[j])){
				rightt[j]=x;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int a,b,job;
	while(cin>>n&&n){
		int res=0;
		memset(rightt,0,sizeof(rightt));
		memset(maps,0,sizeof(maps));
		cin>>m>>k;
		for(int i=0;i<k;i++) {
			cin>>job>>a>>b;
			if(a&&b)	maps[a][b]=true;
		}   
		for(int i=0;i<n;i++){
			memset(used,0,sizeof(used));
			if(findx(i))    res++;
		}
		cout<<res<<endl;
	}
	return 0;
}
