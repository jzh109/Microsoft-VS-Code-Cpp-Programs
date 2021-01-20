#include <bits/stdc++.h>
using namespace std;

int main(){
	bool a[305][305];
	int n;
	char temp;
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((temp=getchar())=='.'){
					a[i][j]=false;
				}
				else{
					a[i][j]=true;
				}
			}
		}
	}
}
