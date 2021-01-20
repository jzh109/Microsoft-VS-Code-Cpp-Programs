#include <bits/stdc++.h>
using namespace std;

int main(){
	FILE* fpin = fopen ("trans.in", "r");
	FILE* fpout = fopen ("trans.out", "w");
	if(fpin==NULL||fpout==NULL) return 0;
	char ch[85], a[85][85];
	int len, k = 0, l = 0;
	memset (ch, 0, sizeof (ch));
	memset (a, 0, sizeof (a));
	fgets (ch, 85, fpin);
	len = strlen (ch);
	for (int i = 0; i < len; i ++){
		if (ch[i] >= '0' && ch[i] <= '9'){
			for (int j = i; j < len; j ++){
				if (ch[j] < '0' || ch[j] > '9') {
					i = j - 1;
					break;
				}
				else	a[k][l++] = ch[j];
			}
			k ++;
			l = 0;
	    }
	}
	fprintf (fpout, "%d\n", k);
	for (int i = 0; i < k; i ++){
		if (i != k - 1)  fprintf (fpout, "%s ", a[i]);
		else    fprintf (fpout, "%s\n", a[i]);
	}
	
	fclose (fpin);
	fclose (fpout);
	return 0;
}
