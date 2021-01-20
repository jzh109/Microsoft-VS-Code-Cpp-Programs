#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct edge
{
    char word[21];
    int numnow;
} words[201], tempstruct;

bool ifaword(char a[])
{ //used to judge if a string is legal word
    int len = strlen(a);
    if (len == 0)
        return false;
    for (int i = 0; i < len; i++)
    {
        if (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] == '-' && i != 0)))
            return false;
    }
    if (strcmp("a", a) == 0 || strcmp("an", a) == 0 || strcmp("the", a) == 0 || strcmp("and", a) == 0)
        return false;
    return true;
}

void pickaword(char a[])
{ //rid all illegal signatures
    int i;
    for (i = 0; a[i] != '\0' && a[i] != ',' && a[i] != '.'; i++)
        ;
    a[i] = '\0';
}

void tolowercase(char str[])
{
    for (int i = 0; i < (int)strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

int readFile(void)
{
    FILE *fpin = fopen("article.txt", "r");
    if (fpin == NULL)
        return -1;
    int lines = 1, structnums = 0;
    char testpoint, tempword[21]; //use a testpoint to test if is a space or the end of line or file
    while ((testpoint = fgetc(fpin)) != EOF)
    { //if the testpoint is end of file
        bool ifanew = true;
        if (testpoint == '\n')
        { //end of the line
            lines++;
            continue;
        }
        else if (testpoint == ' ')
            continue; //a space
        else
        {
            ungetc(testpoint, fpin); //load the charactor back to the file in case one-letter-word appear
            fscanf(fpin, "%s", tempword);
            if (strcmp(tempword, "&ldquo;") == 0 || strcmp(tempword, "&rdquo;") == 0)
            {
                memset(tempword, 0, sizeof(tempword));
            }
        }
        pickaword(tempword);
        tolowercase(tempword);
        for (int i = 0; i < structnums; i++)
        { //judge if this is a new word
            if (strcmp(tempword, words[i].word) == 0)
            {
                ifanew = false;
                break;
            }
        }
        if (ifanew)
        {
            strcpy(words[structnums].word, tempword);
            words[structnums].numnow++;
            structnums++;
        }
    }
    fclose(fpin);
    return structnums;
}

void sortStruct(int structnums)
{
    for (int i = 0; i < structnums - 1; i++)
    { //sort
        for (int j = 0; j < structnums - i - 1; j++)
        {
            if (strcmp(words[j].word, words[j + 1].word) >= 0)
            {
                tempstruct = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tempstruct;
            }
        }
    }
}

void printRes(int structnums)
{
    for (int i = 0; i < structnums; i++)
    {
        if (!ifaword(words[i].word))
            continue;
        printf("%s %d\n", words[i].word, words[i].numnow);
    }
}

int main()
{
    memset(words, 0, sizeof(words));
    int structnums = readFile();
    sortStruct(structnums);
    printRes(structnums);
    return 0;
}