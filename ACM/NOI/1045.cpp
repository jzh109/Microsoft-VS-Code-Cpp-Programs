#include <stdio.h>

int main(){
	int sum1 = 0, sum2 = 0, temp;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			scanf("%d", &temp);
			if(i == j)  sum1 += temp;
			if(i + j == 3)  sum2 += temp;
		}
	}
	printf("%d %d", sum1, sum2);
	return 0;
}
