#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;
int main(){
	FILE* fpin = fopen("Data.txt","r");
	int i = 0;
	char temp[100];
	char name[10],phone[12],qq[12];
	map<char*, char*> person;
	
	while(!feof(fpin)){
		fscanf(fpin, "%s%s%s",name,phone,qq);
		person.
	}
	for(i = 0; i < 5; i ++){
		printf("%d\t%s\t%d\t\n",infomation[i].num,infomation[i].str.c_str(),infomation[i].pri);

	}
}
