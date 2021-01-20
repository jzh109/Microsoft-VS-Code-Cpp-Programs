#include <bits/stdc++.h>
using namespace std;

bool cmp(float a,float b){
	return a>b;
}

int main(){
	float male[40],female[40];
	int n;
	char temp[7];
	float te;
	const char m[]="male";
	while(cin>>n){
		int ma=0,f=0;
		for(int i=0;i<n;i++){
			cin>>temp>>te;
			if(strcmp(temp,m)==0){
				male[ma++]=te;
			}
			else{
				female[f++]=te;
			}
		}
		sort(male,male+ma);
		sort(female,female+f,cmp);
		for(int i=0;i<ma;i++){
			printf("%.2f ",male[i]);
		}
		for(int i=0;i<f;i++){
			printf("%.2f ",female[i]);
		}
		cout<<endl;
	}
	return 0;
}
