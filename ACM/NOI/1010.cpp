#include <stdio.h>
int main(){
	int weight;
	float cost;
	scanf("%d",&weight);
	if(weight<=10)  cost=weight*0.8;
	else if(weight<=20) cost=(weight-10)*0.75+8;
	else if(weight<=30) cost=(weight-20)*0.7+15.5;
	else{
		printf("Fail\n");
		return 0;
	}
	printf("%.2f\n",cost+0.2);
	return 0;
}
