#include <stdio.h>
#include <math.h>
int main(){
	char a[4];
	int s,x;
	scanf("%s",a);
	s=(a[0]-48)*100+(a[1]-48)*10+a[2]-48;
	x=pow(a[0]-48,3)+pow(a[1]-48,3)+pow(a[2]-48,3);
	if(s==x)    printf("YES\n");
	else    printf("NO\n");
	return 0;
}
