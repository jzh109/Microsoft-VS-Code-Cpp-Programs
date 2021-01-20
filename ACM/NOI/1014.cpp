#include <stdio.h>
int main(){
	int score;
	scanf("%d",&score);
	if(score>=90)   printf("Excellent\n");
	else if(score>=80)  printf("Good\n");
	else if(score>=60)	printf("Pass\n");
	else    printf("Fail\n");
	return 0;
}
