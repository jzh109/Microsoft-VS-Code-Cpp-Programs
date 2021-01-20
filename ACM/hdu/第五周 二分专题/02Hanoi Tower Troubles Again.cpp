#include <bits/stdc++.h>
using namespace std;
#define MAX 51

queue<int> balls[MAX];
const double eps = 1e-6;

int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int j = 0;
		while(++j) {
			int i=0;
			for(;i<=n;i++) {
				if(balls[i].empty()){
					balls[i].push(j);
					break;
				}
				if(sqrt(balls[i].back()+j)-(int)sqrt(balls[i].back()+j)<eps) {
					balls[i].push(j);
					break;
				}
			}
			if(i==n)    break;
		}
		if(j<0) {
			cout<<"-1"<<endl;
			continue;
		}
		cout<<--j<<endl;
	}
	return 0;
}
