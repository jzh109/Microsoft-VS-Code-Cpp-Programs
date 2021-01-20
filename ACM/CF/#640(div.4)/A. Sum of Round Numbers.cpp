#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,a,temp;
	set<int> s;
	scanf("%d", &t);
	while(t--){
		int cnt=0,i=0,tens=1;
		s.clear();
		scanf("%d",&a);
		if(a%11==a){
			printf("1\n%d\n",a);
			continue;
		}
		do{
			if((temp = a%10)!=0){
				cnt++;
				s.insert(temp*tens);
			}
			tens=tens*10;
			a=a/10;
		}while(a%10!=a);
		s.insert(a*tens);
		printf("%d\n",++cnt);
		for(set<int>::iterator it = s. begin();it!=s.end();it++){
			printf("%d ",*it);
		}
		printf("\n");
	}
	return 0;
}
