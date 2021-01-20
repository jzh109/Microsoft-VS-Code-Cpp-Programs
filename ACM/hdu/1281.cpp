#include <bits/stdc++.h>
using namespace std;

int n,m,k,rightt[105];
bool used[105],maps[101][101];

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

int funa(){
	int res=0;
	memset(rightt,0,sizeof(rightt));
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		if(findx(i))    res++;
	}
	return res;
}

int main(){
	int a,b,Case=1;
	while(cin>>n>>m>>k){
		memset(maps,0,sizeof(maps));
		for(int i=0;i<k;i++){
			cin>>a>>b;
			maps[a][b]=true;
		}
		int res=funa(),cnt=0;;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(maps[i][j]==true){
					maps[i][j]=false;
					if(res>funa())  cnt++;
					maps[i][j]=true;
				}
			}
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",Case++,cnt,res);
	}
	return 0;
}
