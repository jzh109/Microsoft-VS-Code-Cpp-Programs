#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <fstream>
//using namespace std;
#define MAX 1000005*2

struct Point{
	double x,y;
}points[MAX],res[MAX],temp;

int P,A;
const double pi=acos(-1.0),epsilon=1e-8;

bool cmp(Point a,Point b){
	if(atan2(a.y,a.x)!=atan2(b.y,b.x))  return atan2(a.y,a.x)<atan2(b.y,b.x);
	return a.x<b.x;
}

int crosss(Point a,Point b,Point c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

double dis(Point a,Point b){
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}


double cosss(Point a,Point b,Point c){
	double ang=(pow(dis(a,c),2)+pow(dis(b,c),2)-pow(dis(a,b),2))/(2*dis(a,c)*dis(b,c));
	return ang;
}

int main(){
	FILE* fpin = fopen("extreme.in", "r");
	FILE* fpout = fopen("extreme.out", "w");
	int cou=0;
	fscanf(fpin, "%d%d", &P, &A);
	for(int i=1;i<=P+A;i++)
		fscanf(fpin, "%lf%lf",&points[i].x,&points[i].y);
	fclose(fpin);
	for(int n=P+1;n<=A+P;n++){									//convex
  		int m=0;
  		bool judge=false;
    	for(int k=P+1;k<=A+P;k++){
    		if(k==n)    continue;

    		temp=points[k];
    		points[k]=points[P+1];
    		points[P+1]=temp;
    		
    		std::sort(points+1,points+P+2,cmp);
   			for(int i=1;i<=P+1;i++){
    			if(i==P+1)
        		while(m>1 && crosss(res[m-1],points[i],res[m-2])<=0)
         		   m--;
        		res[m++] = points[i];
   			}
   			
   			temp=points[k];
    		points[k]=points[P+1];
    		points[P+1]=temp;

			double ang=0;
			if(fabs(cosss(res[n-1],res[0],points[n])+1)<=epsilon){//ai在缝合线上？
				judge=true;
				continue;
			}
			for(int j=1;j<m;j++)
				if(fabs(cosss(res[j-1],res[j],points[n])+1)<=epsilon){//ai在边界上？
					judge=true;
					break;
				}
			if(judge==true) continue;
			for(int j=1;j<m;j++)
				ang+=acos(cosss(res[j-1],res[j],points[n]));
			ang+=acos(cosss(res[m-1],res[0],points[n]));
			if(fabs(ang-2*pi)<=epsilon) judge=true;//ai在凸包内部？
		}
		if(judge==false) cou++;//不在？
	}
	fprintf(fpout,"%d\n",cou);
	fclose(fpout);
	return 0;
}
