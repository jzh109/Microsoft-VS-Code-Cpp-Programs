#include <stdio.h>
#include <string.h>

struct edge {
	char word[21];
	int lines[201], numnow;
}words[201], tempstruct;

bool ifaword (char a[]) {                                                       //used to judge if a string is legal word
	int len = strlen(a);
	if (len == 0)    return false;
	for (int i = 0; i < len; i ++) {
		if (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] == '-' && i != 0)))	return false;
	}
	if (strcmp ("a", a) == 0 || strcmp ("an", a) == 0 || strcmp ("the", a) == 0 || strcmp ("and", a) == 0)	return false;
	return true;
}

void pickaword (char a[]){														//rid all illegal signatures
	int i;
	for (i = 0; a[i] != '\0' && a[i] != ',' && a[i] != '.'; i ++);
	a[i] = '\0';
}

int main() {
	memset (words, 0, sizeof (words));
	FILE* fpin = fopen ("crossin.txt", "r");
	if (fpin == NULL) return 0;
	int lines = 1, structnums = 0;
	char testpoint, tempword[21];												//use a testpoint to test if is a space or the end of line or file
	while ((testpoint = fgetc (fpin)) != EOF){									//if the testpoint is end of file
	bool ifanew = true;
		if (testpoint == '\n'){													//end of the line
			lines ++;
			continue;
		}
		else if (testpoint == ' ')	continue;									//a space
		else{
			ungetc (testpoint, fpin);											//load the charactor back to the file in case one-letter-word appear
			fscanf (fpin, "%s", tempword);
		}
		pickaword (tempword);
		for (int i=0; i < structnums; i ++) {                                   //judge if this is a new word
			if (strcmp (tempword, words[i].word) == 0) {
				words[i].lines[words[i].numnow ++] = lines;
				ifanew = false;
				break;
			}
		}
		if (ifanew){
			strcpy (words[structnums].word, tempword);
			words[structnums].lines[words[structnums].numnow] = lines;
			words[structnums].numnow ++;
			structnums ++;
		}
	}
	fclose (fpin);
	
	for(int i = 0; i < structnums - 1; i ++) {                                  //sort
		for (int j = 0; j < structnums - i - 1; j ++) {
			if (strcmp(words[j].word, words[j + 1].word) >= 0) {
				tempstruct = words[j];
				words[j] = words[j + 1];
				words[j + 1] = tempstruct;
			}
		}
	}
	
	FILE* fpout = fopen ("crossout.txt", "w");
	if (fpout == NULL)  return 0;
	for (int i = 0; i < structnums; i ++) {
		if (!ifaword(words[i].word))	 continue;
		fprintf (fpout, "%s:", words[i].word);
		if (words[i].numnow == 1)	fprintf (fpout, "%d\n", words[i].lines[0]);
		else{
			for (int j = 0; j < words[i].numnow; j ++) {
				if (j == 0)  fprintf (fpout, "%d", words[i].lines[0]);
				else if (words[i].lines[j] != words[i].lines[j - 1])	fprintf (fpout, ",%d", words[i].lines[j]);
				if (j == words[i].numnow - 1)    fprintf (fpout, "\n");
			}
		}
	}
	fclose (fpout);
	return 0;
}
