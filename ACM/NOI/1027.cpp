#include <stdio.h>
#include <string.h>
int main(){
	char a[20];
	int b=0;
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		b+=(a[i]-'0');
	}
	printf("%d\n",b);
	return 0;
}
