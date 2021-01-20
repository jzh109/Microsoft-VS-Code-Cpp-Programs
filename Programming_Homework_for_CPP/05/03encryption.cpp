#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void word (char a[]){
	int len, k = 1;
	char asc[51];
	memset (asc, 0, sizeof (asc));
	len = strlen (a);
	asc[0] = a[0];
	for (int i = 1; i < len; i ++) {
		bool same = false;
		for (int j = 0; j < k; j ++) {
			if (asc[j] == a[i]) {
				same = true;
				break;
			}
		}
		if (!same)   asc[k++] = a[i];
	}
	strcpy(a, asc);
}

void password (char a[], char x[]) {
	char b[27];
	int len, k = 0;
	memset (b, 0, sizeof (b));
	word (a);
	len = strlen (a);
	strcat (b, a);
	for (int i = len; i < 26; i ++) {
		bool judge = false;
		for (int j = 0; j < len; j++){
			if (a[j] == 'z' - k){
				judge = true;
				i --;
				break;
			}
		}
		if (!judge)	b[i] = 'z' - k;
		k ++;
	}
	strcpy(x, b);
}

void encrypt (char a[], char x[], char c[]) {
	int len;
	len = strlen (a);
	for (int i = 0; i < len; i ++)
		if (a[i] >= 'a' && a[i] <= 'z')	c[i] = x[a[i] - 'a'];
		else	c[i] = a[i];
}

int main () {
	char key[51], format[27], from[100], to[100];
	memset (key, 0, sizeof (key));
	memset (format, 0, sizeof (format));
	memset (from, 0, sizeof (from));
	memset (to, 0, sizeof (to));
	
	scanf ("%s", key);
	password (key, format);

	FILE* fpin = fopen ("encrypt.txt","r");
	if (fpin == NULL)   return 0;
	fgets (from, 100, fpin);
	fclose (fpin);
	
	encrypt (from, format, to);

	FILE* fpout = fopen ("output.txt","w");
	fputs (to, fpout);
	fclose (fpout);
	
	return 0;
}
