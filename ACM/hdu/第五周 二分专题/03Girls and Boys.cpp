#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

int maps[MAX][MAX],rightt[MAX],n,m;
bool used[MAX];

bool findx(int x){
	for(int i=0;i<n;i++){
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
	int a,b,t;
	while(cin>>n){
		int res=0;
		memset(maps,0,sizeof(maps));
		memset(rightt,0,sizeof(rightt));
		for(int i=0;i<n;i++){
			scanf("%d: (%d)",&a,&t);
			for(int j=0;j<t;j++){
				cin>>b;
				maps[a][b]=true;
			}
		}
		for(int i=0;i<n;i++){
			memset(used,0,sizeof(used));
			if(findx(i))    res++;
		}
		cout<<n-res/2<<endl;
	}
	return 0;
}
