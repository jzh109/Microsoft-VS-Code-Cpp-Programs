#include <stdio.h>
#include <string.h>
int main(){
	int len,n;
	char pin[51],temp;
	
	scanf("%d",&n);
	getchar();
	while(n--){
		bool num=false,ln=false,LE=false,le=false,si=false;
		gets(pin);
		len=strlen(pin);
		if(len>=8&&len<=16)	ln=true;
		if(ln==false){
			printf("NO\n");
			continue;
		}
		for(int i=0;i<len;i++){
			temp=pin[i];
			if(temp>='a'&&temp<='z'){
				le=true;
				continue;
			}
			else if(temp>='A'&&temp<='Z'){
				LE=true;
				continue;
			}
			else if(temp>='0'&&temp<='9'){
				num=true;
				continue;
			}
			else if(temp=='~'||temp=='!'||temp=='@'||temp=='#'||temp=='$'||temp=='%'||temp=='^'){
				si=true;
				continue;
			}
		}
		if(num+LE+le+si>=3)
			printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
} 
