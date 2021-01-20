#include <stdio.h>
int main(){
	int a=0,b=0,c=0,n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
  		scanf("%d",&m); a+=m;
  		scanf("%d",&m); b+=m;
  		scanf("%d",&m);	c+=m;
	}
	printf("%d %d %d %d",a,b,c,a+b+c);
	return 0;
}
