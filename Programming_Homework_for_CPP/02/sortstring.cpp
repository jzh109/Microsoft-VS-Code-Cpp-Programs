#include <bits/stdc++.h>
using namespace std;

int main(){
	char str[100];
	int len;
	gets(str);
	len = strlen (str);
	sort(str , str + len);
 	if(len == 1)
		puts(str);
	else{
		putchar(str[0]);
		for(int i=1;i<len;i++){
			if(str[i-1] != str[i])  putchar(str[i]);
		}
	}
	return 0;
}
