#include <stdio.h>
int main(){
	int n;
	char x;
	scanf("%d",&n);
	getchar();
	while(n--){
		int a=0,e=0,i=0,o=0,u=0;
		while(1){
			x=getchar();
			if(x=='\n')	break;
			switch(x){
				case 'a':
					a++;
					break;
				case 'e':
					e++;
					break;
				case 'i':
					i++;
					break;
				case 'o':
					o++;
					break;
				case 'u':
					u++;
					break;
			}
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
		if(n!=0)	printf("\n");
	}
	return 0;
} 
