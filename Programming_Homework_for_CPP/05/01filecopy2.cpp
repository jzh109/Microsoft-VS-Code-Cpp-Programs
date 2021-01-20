/*#include <stdio.h>
#include <stdlib.h>
int main(){
	int i=0;
	char a[20][20];
	FILE* fpin = fopen("filein.txt","r");
	if(fpin == NULL)    exit(0);
	while(!feof(fpin)){
		fscanf(fpin,"%s",a[i++]);
	}
	fclose(fpin);
	FILE* fpout = fopen("fileout.txt","w");
	for(int j=0;j<i;j++){
		fprintf(fpout,"%s ",a[j]);
	}
	fclose(fpout);
	return 0;
}*/
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

int main(){
	FILE* fpin = fopen("filein.txt","r");
	FILE* fpout = fopen("fileout.txt","w");
	string temp;
	queue<string> word;
	
	while(!feof(fpin)){
		fscanf(fpin,"%s",&temp);
		word.push(temp);
	}
	while(!word.empty()){
		temp = word.front();
		fprintf(fpout,"%s ",temp.data());
		word.pop();
	}
	fclose(fpin);
	fclose(fpout);
}
