#include <bits/stdc++.h>
using namespace std;

signed main(){
	//ios::sync_with_stdio(false);
	//std::cin.tie(NULL);
	int m,n;
	bool a[100][100],b[100][100];
	cin>>m>>n;
		int count = 0;
		//memset(a,0,sizeof(a));
		//memset(b,0,sizeof(b));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>b[i][j];
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(!(a[i][j] xor b[i][j])) count++;
			}
		}
		printf("%.2f\n",(float)count*100/(m*n));
	return 0;
}



	
