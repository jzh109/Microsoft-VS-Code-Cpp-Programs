#include <bits/stdc++.h>
using namespace std;

int main() {
	char a[4];
	while(gets(a)){
		sort(a, a+3);
		for(int i=0;i<3;i++){
			if(i==2)printf("%c\n",a[i]);
			else printf("%c ",a[i]);
		}
	}
	return 0;
}
