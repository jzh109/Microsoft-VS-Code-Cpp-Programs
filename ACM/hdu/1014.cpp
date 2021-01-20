#include<bits/stdc++.h>
using namespace std;
int yuan(char c)
{
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
  	return 1;
  return 0;
}
int main()
{
    string str;
    cin>>str;
    while(str!="end")
	{
        int flag1=0;
        int flag2=0;
        int flag3=0;
        for(int i=0;i<str.length();i++)
		{
        	if(yuan(str[i]))flag1=1;
        	if(i>=1)
			{
            	if(str[i]!='e'&&str[i]!='o')
            	if(str[i]==str[i-1])flag2=1;
        	}
        	if(i>=2)
			{
         	    if(yuan(str[i])&&yuan(str[i-1])&&yuan(str[i-2]))flag3=1;
            	if(!yuan(str[i])&&!yuan(str[i-1])&&!yuan(str[i-2]))flag3=1;
        	}
        }
        if(flag1&&!flag2&&!flag3)cout<<"<"<<str<<"> is acceptable."<<endl;
        else cout<<"<"<<str<<"> is not acceptable."<<endl;
        cin>>str;
    }
    return 0;
}
