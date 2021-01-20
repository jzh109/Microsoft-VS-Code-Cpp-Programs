#include <stdio.h>

int main(){
	int n, min, max,a[100];
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n ; i ++)
			scanf("%d", &a[i]);
		max = min = a[0];
		for(int i = 0 ; i < n ; i ++){
			if(max < a[i])  max = a[i];
			if(min > a[i])  min = a[i];
		}
		printf("%d %d", max, min);
	}
	return 0;
}
