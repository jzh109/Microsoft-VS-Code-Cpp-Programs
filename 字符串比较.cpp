#include <stdio.h>
#include <string.h>
void com(char B[]);
int main()
{
	char Str_B[50];				//定义Str_B 
	gets(Str_B);				//输入Str_B 
	com(Str_B);					//转入函数 
	return 0;
}
void com(char B[])
{
	char Str_A[8]={"abcdefg"},Str_C[100];int len,i,j,k=0,temp[100];
	len=strlen(B);				//量出B的长度 
	for(i=0;i<len;i++){			//拿出B中序号为i的元素 
		for(j=0;j<8;j++){		//将i元素与Str_A中所有元素对比 
			if(B[i]==Str_A[j]){
				temp[k]=i;		//若相同记下此序号到temp里，序号为k 
				k++;}}}			//序号加一 
	k=0;j=0;					//清零 
	for(i=0;i<len;i++){
		if(i==temp[k])
			k++;				//若B序号在temp里出现，temp序号加1，B序号加1 
		else{
			Str_C[j]=B[i];
			j++;}}				//若B序号未在temp里出现，赋值，Str_C序号加1
	puts(Str_C);				//输出Str_C 
}
