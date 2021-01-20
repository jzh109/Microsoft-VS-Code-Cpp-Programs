#include <stdio.h>
int main(){
	int x,mod;
	scanf("%d",&x);
	mod=x%123;
	if(mod>=97&&mod<=122){
		printf("%c\n",mod);
		return 0;
    }
    else if((mod=x%91)&&mod>=65&&mod<=90){
    	printf("%c\n",mod);
    	return 0;
	}
	else    printf("*\n");
	return 0;
}
