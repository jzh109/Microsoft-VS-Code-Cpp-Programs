#include <iostream>
using namespace std;

//move the large one ahead
void swapp(int* a, int* b) {
	int temp;
	if(*a > *b){
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

//find if two segments have in public
int samePart(int x11, int x12, int x21, int x22) {
	swapp(&x11, &x12);
	swapp(&x21, &x22);
	if(x11 < x21 && x22 < x12)  return x22 - x21;
	else if(x21 < x11 && x12 < x22) return x12 - x11;
	else if(x11 < x21 && x21 < x12) return x12 - x21;
	else if(x11 < x22 && x22 < x12)	return x22 - x11;
	else	return 0;
}

int main() {
	int Ax1, Ay1, Ax2, Ay2, Bx1, By1, Bx2, By2;
	cin>>Ax1>>Ay1>>Ax2>>Ay2>>Bx1>>By1>>Bx2>>By2;
	int a = samePart(Ax1, Ax2, Bx1, Bx2);
	int b = samePart(Ay1, Ay2, By1, By2);
	
	cout<<a * b<<endl;
	return 0;
}
