#include <bits/stdc++.h>
using namespace std;

void change (char* a, int lena) {                                               //swap an array from its head to bottom
	char temp;
	for (int i = 0; i < lena / 2; i ++) {
		temp = a[i];
		a[i] = a[lena - i - 1];
		a[lena - i - 1] = temp;
	}
}

void lower (char* a, int lena) {                                                //minus '0' to int number
	for (int i = 0; i < lena; i ++)
		a[i] -= '0';
	change (a, lena);                											//swap the array from head to bottom
}

int main () {
	char a[85], b[85], res[85];
	int v = 0, lena, lenb, len;
	bool judge = true;                                                          //stands for number(a)>number(b)?
	memset (a, 0, sizeof (a));
	memset (b, 0, sizeof (b));
	memset (res, 0, sizeof (res));                                              //initial all arrays
	scanf ("%s %s", a, b);
	lena = strlen (a);
	lenb = strlen (b);
	len = lena > lenb ? lena : lenb;
	
	lower (a, lena);
	lower (b, lenb);                                                            //change char to int
	
	for (int i = 0; i < len; i ++) {
		if (lena > lenb)   break;
		else if (lena < lenb)	judge = false;
		else if (a[lena - 1 - i] > b[lenb - 1 - i])    break;
		else if (a[lena - 1 -i ] < b[lenb - 1 - i])	judge = false;
		else    continue;
	}                                                                           //compare number(a) with number(b)
	
	if (judge == true) {                                                        //if number(a) > number(b)
		for (int i = 0; i < len; i ++){
			if (a[i] > b[i] || (a[i] == b[i] && res[i] == 0))   res[i] += a[i]- b[i];
			else {                                                              //if borrowed
				res[i] += a[i] + 10 - b[i];
				res[i + 1] = -1;
			}
		}
		for (int i = 0; i < len; i ++)
			res[i] += '0';
		change (res, len);                                                      //swap the result
		for (v = 0; res[v] == '0'; v ++);                                       //find the first position of the result (v)
		if (v == len)  printf ("0\n");
		puts (res + v);
	}
	
	else {
		for (int i = 0; i < len; i ++){
			if (b[i] > a[i] || (a[i] == b[i] && res[i] == 0))   res[i] += b[i] - a[i];
			else {
				res[i] += b[i] + 10 - a[i];
				res[i + 1] = -1;
			}
		}
		for (int i = 0; i < len; i ++)
			res[i] += '0';
		change (res, len);
		printf ("-");
		for (v = 0; res[v] == '0'; v ++);
		if (v == len)  printf ("0\n");
		puts (res + v);
	}
	return 0;
}
