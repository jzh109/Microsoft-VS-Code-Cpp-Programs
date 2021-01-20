#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;
int main()
{
    int t,i;
    char order;
    float re,a,b;
    while(scanf("%d",&t)!=EOF)
    {
    	for(i=0;i<t;i++)
    	{
    		fflush(stdin);
    		scanf("%c %f %f",&order,&a,&b);
    		switch(order)
    		{
    			case '+':
    				re=a+b;
    				break;
    			case '-':
    				re=a-b;
    				break;
    			case '*':
    				re=a*b;
    				break;
				case '/':
    				re=a/b;
			}
			if((re-(int)re)<1e-8&&(re-(int)re)>-1e-8)
				printf("%.0f\n",re);
			else
				printf("%.2f\n",re);
		}
	}
	system("pause");
	return 0;
}
