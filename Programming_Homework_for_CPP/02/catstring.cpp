#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void  str_bin(char str1[ ], char str2[ ]){
	strcat(str1,str2);
	sort(str1,str1+strlen(str1));
}

int main(){
	char str1[201],str2[100];
	gets(str1);
	gets(str2);
	str_bin(str1,str2);	
	puts(str1);
}
