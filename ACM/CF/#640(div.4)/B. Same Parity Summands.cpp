#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,k,ints;
	const double eps=1e-6;
	double bits,temp;
	long long n;
	scanf("%d",&t);
	while(t--){
		int sum=0,cnt=0;
		bool find=false;
		scanf("%lld%d",&n,&k);
		temp=(double)n/k;
		if((int)n<k){
			printf("NO\n");
			continue;
		}
		if(temp-(int)temp<eps){
			printf("YES\n");
			for(int i=0;i<k;i++)    printf("%d ",(int)temp);
			printf("\n");
			continue;
		}
		else{
			temp=(int)temp;
			do{
				sum=cnt*(temp+2)+temp*(k-cnt);
				cnt++;
			}while(sum!=n&&cnt<=k);
			cnt--;
			if(cnt!=k)find=true;
			if(!find){
				temp--;
				if(temp==0){
					printf("NO\n");
					continue;
				}
				cnt=0;
				do{
					sum=cnt*(temp+2)+temp*(k-cnt);
					cnt++;
				}while(sum!=n&&cnt<=k);
				cnt--;
				if(cnt!=k)find=true;
			}
		}
		if(!find)  printf("NO\n");
		else{
			printf("YES\n");
			for(int i=0;i<cnt;i++){
				printf("%d ",(int)temp+2);
			}
			for(int i=cnt;i<k;i++){
				printf("%d ",(int)temp);
			}
			printf("\n");
		}
	}
	return 0;
}
