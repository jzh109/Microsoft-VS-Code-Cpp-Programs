#include <stdio.h>
#include <string.h>
void com(char B[]);
int main()
{
	char Str_B[50];				//����Str_B 
	gets(Str_B);				//����Str_B 
	com(Str_B);					//ת�뺯�� 
	return 0;
}
void com(char B[])
{
	char Str_A[8]={"abcdefg"},Str_C[100];int len,i,j,k=0,temp[100];
	len=strlen(B);				//����B�ĳ��� 
	for(i=0;i<len;i++){			//�ó�B�����Ϊi��Ԫ�� 
		for(j=0;j<8;j++){		//��iԪ����Str_A������Ԫ�ضԱ� 
			if(B[i]==Str_A[j]){
				temp[k]=i;		//����ͬ���´���ŵ�temp����Ϊk 
				k++;}}}			//��ż�һ 
	k=0;j=0;					//���� 
	for(i=0;i<len;i++){
		if(i==temp[k])
			k++;				//��B�����temp����֣�temp��ż�1��B��ż�1 
		else{
			Str_C[j]=B[i];
			j++;}}				//��B���δ��temp����֣���ֵ��Str_C��ż�1
	puts(Str_C);				//���Str_C 
}
