#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

void expand(const char* s1, char* s2) {
	int len, j = 1;
	len = strlen(s1);
	s2[0] = s1[0];
	for (int i = 1; i < len - 1; i++) {
		if (s1[i] == '-' && (s1[i - 1] < s1[i + 1]) && ((s1[i - 1] >= 'A' && s1[i + 1] <= 'z')||(s1[i - 1] >= '0' && s1[i + 1] <= '9'))) {
			for (int k = 1; k < s1[i + 1] - s1[i - 1]; k++)
				s2[j++] = s1[i - 1] + k ;
			continue;
		}
		s2[j++] = s1[i];
	}
	s2[j++] = s1[len - 1];
	s2[j] = '\0';
}

long size(const char* s1) {
	int len, bit = 0;
	len = strlen(s1);
	for (int i = 0; i < len; i++) {
		if (s1[i] == '-' && (s1[i - 1] < s1[i + 1]) && ((s1[i - 1] >= 'A' && s1[i + 1] <= 'z')||(s1[i - 1] >= '0' && s1[i + 1] <= '9'))){
			for (int k = 1; k < s1[i + 1] - s1[i - 1]; k++)
				bit++;
			continue;
		}
		bit++;
	}
	return ++bit;
}

int main() {
	string str1, str2;
	char a = 0, * out = NULL;
	const char* line = NULL;
	
	while ((a = getchar()) != EOF) str1.append(1, a);
	line = (char*)malloc(str1.size());
	line = str1.c_str();
	out = (char*)malloc(size(line));
	
	expand(line, out);
	printf("%s",out);
	return 0;
}

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expand(char s1[], char s2[]) {
	int len, j = 1;
	len = strlen(s1);
	s2[0] = s1[0];
	for (int i = 1; s1[i] != '\0'; i++) {
		if (s1[i] == '-' && ((s1[i - 1] >= 'A' && s1[i + 1] <= 'Z') || (s1[i - 1] >= 'a' && s1[i + 1] <= 'z') || (s1[i - 1] >= '0' && s1[i + 1] <= '9'))) {
			for (int k = 1; k < s1[i + 1] - s1[i - 1]; k++)
				s2[j++] = s1[i - 1] + k;
			continue;
		}
		s2[j++] = s1[i];
	}
	s2[j] = '\0';
}

int main() {
	char a, out[100], line[100];
	memset(line,0,sizeof(line));
	memset(out,0,sizeof(out));
	int m = 0;
	while (1) {
		a = getchar();
		if (a == EOF)	break;
		else line[m++] = a;
	}
	expand(line, out);
	printf("%s", out);
	return 0;
}*/
