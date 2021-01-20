#include <stdio.h>
#include <math.h>
int main(){
	char a[7];
	int b;
	scanf("%s",a);
	for(int i=0;i<3;i++)
		a[i]=a[i]-'0';
	for(int i=0;i<3;i++)
		a[i+3]=a[i];
	b=a[0]*100000+a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
	b=b/7/11/13;
	printf("%d\n",b);
}
