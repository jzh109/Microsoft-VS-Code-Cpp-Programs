#include <bits/stdc++.h>
//using namespace std;

bool cmp(int a , int b){
	return a > b;
}

int main(){
	int a[45] , i = 0 , t = 0 , j = 0;
	while (t != 2){
		scanf ("%d" , &a[i ++]);
		if (getchar() == '\n') t ++;
	} 
	std::sort (a , a + i , cmp);
	
	if ((i == 2) && (a[0] == a[1]))	return 0;
	if ((i == 2) && (a[0] != a[1])){
		printf ("%d %d " , a[0] , a[1]);
		return 0;
	}
	if (a[0] != a[1])	printf ("%d " , a[0]);
	for (j = 1 ; j < i - 1 ; j ++){
		if ((a[j] == a[j + 1]) || (a[j] == a[j - 1]))	continue;
		printf ("%d " , a[j]);
	}
	if (a[i - 1] != a[i - 2])	printf ("%d " , a[i - 1]);
	return 0;
}
