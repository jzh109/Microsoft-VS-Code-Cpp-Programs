#include <bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
}points[1000000],res[1000000];

bool cmp(Point a,Point b){
	if(atan2(a.y,a.x)!=atan2(b.y,b.x))  return atan2(a.y,a.x)<atan2(b.y,b.x);
	return a.x<b.x;
}

int cross(Point a,Point b,Point c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

double square
