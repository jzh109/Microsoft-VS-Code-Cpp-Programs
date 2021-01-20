#include <stdio.h>
#include <string.h>
#define FORMAT "SCHOOL NUM:%s\nNAME:%s\nSEX:%s\nCLASS:%s\nID NUM:%s\n"

int main()
{
	//Definitions
	struct stu_info
	{
		char num[14];
		char name[20];
		char sex[7];
		char cls[10];
		char id[19];
	}stu[20];
	int n;
	char tar[14];
	
	//input data
	printf("Input the number of students:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Input No.%d student's information:\n",i+1);
		printf("SCHOOL NUM:");scanf("%s",stu[i].num);getchar();
		printf("NAME:");gets(stu[i].name);
		printf("SEX:");scanf("%s",stu[i].sex);
		printf("CLASS:");scanf("%s",stu[i].cls);
		printf("ID NUM:");scanf("%s",stu[i].id);
	}
	
	//input search target
	printf("Input the SCHOOL NUM of the students:");
	scanf("%s",tar);
	
	//search target
	for(int i=0;i<n;i++)
	{
		if(strcmp(tar,stu[i].num)==0)
			printf(FORMAT,stu[i].num,stu[i].name,stu[i].sex,stu[i].cls,stu[i].id);
	}
	return 0;
}
