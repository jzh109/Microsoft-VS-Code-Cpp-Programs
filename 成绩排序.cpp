#include <stdio.h>
#include <string.h>
int main()
{
	char name[][8]={"Wang","Li","Wu","Qi","Liu","Bai","He","Zhang"},ch;
	int i,j,s,c,score[8]={98,77,89,92,60,77,88,92},grade[8]={1,2,3,4,5,6,7,8};
	for(i=0;i<8;i++)
	{
		for(j=0;j<8-i;j++)
		{
			if(score[j]<=score[j+1])
			{
				c=score[j];
				score[j]=score[j+1];
				score[j+1]=c;
				c=grade[j];
				grade[j]=grade[j+1];
				grade[j+1]=c;
				for(s=0;s<8;s++)
				{
					ch=name[j][s];
					name[j][s]=name[j+1][s];
					name[j+1][s]=ch;
				}
			}
		}
	}
	printf("Name\t\tscore\t\tgrade\t\n");
	printf("----------------------------------\n");
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%c",name[i][j]);
		printf("\t%d\t\t%d\t",score[i],grade[i]);
		printf("\n");							
	}
}
