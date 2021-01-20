#include <stdio.h>
int main(){
	int boys,girls;
	scanf("%d%d",&boys,&girls);
	if(boys+girls<10)   printf("water\n");
	else if(boys>girls) printf("tree\n");
	else    printf("tea\n");
	return 0;
}
