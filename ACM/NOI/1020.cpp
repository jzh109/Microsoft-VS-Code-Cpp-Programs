#include <stdio.h>
#include <string.h>
int main(){
	char a[5];
	int b=0,i=0;
	gets(a);
	b=strlen(a);
	printf("%d\n",b);
	while(a[i])
		printf("%c\n",a[i++]);
	return 0;
}
