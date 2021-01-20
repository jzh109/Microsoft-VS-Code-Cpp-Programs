#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct textLine
{
	char word[50];
	int num;
};

//insert to array
//insert to array
void insert(textLine *array, char *a, int *num_ptr)
{
	if (array == NULL)
	{
		return;
	}
	int i;
	for (i = 0; i < *num_ptr && strcmp(a, array[i].word) != 0; i++)
		;
	if (i < *num_ptr)
	{
		array[i].num++;
	}
	else
	{
		strcpy(array[i].word, a);
		array[i].num++;
		*num_ptr = *num_ptr + 1;
	}
}

//judge if a letter
bool judge(const char a)
{
	return ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'));
}

//comparison function
bool cmp(textLine p1, textLine p2)
{
	return strcmp(p1.word, p2.word) >= 0 ? false : true;
}

//change to lower case
void toLowerCase(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
}

//read file
void readFile(textLine *array, int &num)
{
	FILE *fpin;
	if ((fpin = fopen("article.txt", "r")) == NULL)
	{
		puts("open the file failed\n");
		exit(0);
	}
	while (!feof(fpin))
	{
		char temp[100] = "\0";
		fgets(temp, 100, fpin);

		int j = 0, k = strlen(temp);
		for (int i = 0; i < k;)
		{
			for (; !judge(temp[i]) && i < k; i++)
				;
			if (i < k)
			{
				for (j = i + 1; judge(temp[j]) && j < k; j++)
					;
				temp[j] = '\0';

				toLowerCase(&temp[i]);
				insert(array, &temp[i], &num);
				i = j;
			}
		}
	}
	fclose(fpin);
}

int main(int argc, const char **args)
{
	textLine array[200] = {0};
	int num = 0;

	readFile(array, num);
	std::sort(array, array + num, cmp);

	for (int i = 0; i < num; i++)
	{
		printf("%s %d\n", array[i].word, array[i].num);
	}
	return 0;
}
