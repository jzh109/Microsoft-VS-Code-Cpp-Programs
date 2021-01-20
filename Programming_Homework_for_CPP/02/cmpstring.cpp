#include <bits/stdc++.h>
using namespace std;

int strend(char* s,char* t){
	int lens,lent,i,j;
	bool judge = false;
	lens = strlen(s);
	lent = strlen(t);
	for(i = lens-lent , j = 0 ; j < lent ; i ++ , j ++){
		if(s[i] == t[j])    judge = true;
		else{
			judge = false;
			break;
		}
	}
	return (int)judge;
}

int main(){
	char s[101], t[101];
	int k;
	gets(s);
	gets(t);
	k = strend(s,t);
	if(k == 1)  printf("Yes\n");
	else    printf("No\n");
	return 0;
}
