#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maps[MAX][MAX],rightt[125],n,m;
bool used[125];

bool findx(int x){
	for(int i=1;i<=m;i++){
		if(maps[x][i]&&!used[i]){
			used[i]=true;
			if(!rightt[i]||findx(rightt[i])){
				rightt[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		int res=0;
		cin>>m>>n;
		memset(rightt,0,sizeof(rightt));
		memset(maps,0,sizeof(maps));
		for(int i=0;i<n;i++){
			cin>>a>>b;
			maps[a][b]=true;
		}
		for(int i=1;i<=m;i++){
			memset(used,0,sizeof(used));
			if(findx(i))    res++;
		}
		cout<<m-res<<endl;
	}
	return 0;
}
