#include <stdio.h>
#include <string.h>
#include <ctype.h>

void change(FILE* fpin,FILE* fpout,char a[],char b[]){
	int lena,lenb,len;
	char temp[100],back[100];
	memset(temp,0,sizeof(temp));
	lena=strlen(a);
	lenb=strlen(b);
	for(int i=0;i<lena;i++)    a[i]=a[i]<tolower(a[i])?tolower(a[i]):a[i];
	while(!feof(fpin)){
		bool _new = false;
		fgets(temp,100,fpin);
		len=strlen(temp);
		for(int i=0;i<len;i++){
			for(int j=0;j<lena;j++){
				if(!(temp[i+j] == a[j] || temp[i+j] == a[j] + 32 || temp[i+j] == a[j] - 32))   break;
				if(j == lena - 1)	_new = true;
			}
			if(_new){
 				memset(back,0,sizeof(back));
				int k=i+lena,x=0;
				while(temp[k]!='\0'){
					back[x++]=temp[k++];
				}
				temp[i]='\0';
				strcat(temp,b);
				strcat(temp,back);
				i = i + lenb - 1;
				_new=false;
			}
		}
		fputs(temp,fpout);
	}
}

int main(){
	char a[10],b[10];
 	memset(a,0,sizeof(a));
 	memset(b,0,sizeof(b));
	scanf("%s%s",a,b);
	FILE* fpin = fopen("filein.txt","r");
	FILE* fpout = fopen("fileout.txt","w");
 	change(fpin,fpout,a,b);
	fclose(fpin);
	fclose(fpout);
	return 0;
}
