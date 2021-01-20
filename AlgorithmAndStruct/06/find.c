#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 'a' - 'A';
    return c;
}

// int isFind(char tempLine[], int offset, char inputString[]){
//     int inputPointer = 0;
//     int tempLinePointer = 0;

//     while(inputString[inputPointer]!='0'){
//         if(toLower(tempLine[offset+tempLinePointer])!=toLower(inputString[inputPointer])){
//             return 0;
//         }
//     }
//     return 1;
// }

int isMatched(char tempLine[], int offset, char inputString[], char output[])
{
    int inputPointer = 0;
    int tempLinePointer = 0;
    int len = strlen(inputString);
    char *meta = (char *)calloc(1, 105);
    int i, j;

    while (inputPointer < len)
    {
        if (inputString[inputPointer] != '[' && inputString[inputPointer] != '*')
        {
            if (toLower(inputString[inputPointer]) == toLower(tempLine[offset + tempLinePointer]))
            {
                inputPointer++;
                tempLinePointer++;
            }
            else
                break;
        }
        else if (inputString[inputPointer] == '[')
        {
            i = 0;
            inputPointer++;
            while (inputString[inputPointer] != ']')
            {
                meta[i++] = inputString[inputPointer];
                inputPointer++;
            }
            meta[i] = '\0';
            if (meta[0] == '^')
            {
                for (j = 1; j < i; j++)
                {
                    if (toLower(tempLine[offset + tempLinePointer]) == toLower(meta[j]))
                        break;
                }
                if (j == i)
                {
                    tempLinePointer++;
                    inputPointer++;
                }
                else
                    break;
            }
            else
            {
                int find = 0;
                for (j = 0; j < i; j++)
                {
                    if (toLower(tempLine[offset + tempLinePointer]) == toLower(meta[j]))
                    {
                        find = 1;
                        break;
                    }
                }
                if (find)
                {
                    inputPointer++;
                    tempLinePointer++;
                }
                else
                    break;
            }
        }
        else if (inputString[inputPointer] == '*')
        {
            inputPointer++;
            if (inputPointer == len)
            { //End of inputString
                while (tempLine[offset + tempLinePointer] != '\0')
                    tempLinePointer++;
                break;
            }
            else if (inputString[inputPointer] != '[')
            {
                // int find = 0;

                while (toLower(tempLine[offset + tempLinePointer]) != toLower(inputString[inputPointer]))
                {
                    tempLinePointer++;
                    if (tempLine[offset + tempLinePointer] == '\0')
                        break;
                }
                if (toLower(tempLine[offset + tempLinePointer]) == toLower(inputString[inputPointer]))
                {
                    tempLinePointer++;
                    inputPointer++;
                }
                else /* abc*deg */ /* abc789defdeg */
                    break;
            }
            else if (inputString[inputPointer] == '[')
            {
                i = 0;
                while (inputString[inputPointer] != ']')
                {
                    meta[i++] = inputString[inputPointer];
                    inputPointer++;
                }
                meta[i] = '\0';
                while (tempLine[offset + tempLinePointer] != '\0')
                {
                    if (meta[0] == '^')
                    {
                        for (j = 1; j < i; j++)
                        {
                            if (toLower(tempLine[offset + tempLinePointer]) == toLower(meta[j]))
                            {
                                tempLinePointer++;
                                break;
                            }
                        }
                        if (j == i)
                        {
                            tempLinePointer++;
                            inputPointer++;
                            break;
                        }
                    }
                    else
                    {
                        int find = 0;
                        for (j = 0; j < i; j++)
                        {
                            if (toLower(tempLine[offset + tempLinePointer]) == toLower(meta[j]))
                            {
                                find = 1;
                                break;
                            }
                        }
                        if (find)
                        {
                            inputPointer++;
                            tempLinePointer++;
                            break;
                        }
                        else
                            tempLinePointer++;
                    }
                }
            }
        }
        if (tempLine[offset + tempLinePointer] == '\0')
            break;
    }

    if (inputPointer == len)
    {
        for (j = 0; j < tempLinePointer; j++)
            output[j] = tempLine[offset + j];
        output[j] = '\0';
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char *inputString = (char *)calloc(1, 25);
    char *tempLine = (char *)calloc(1, 85);
    char *output = (char *)calloc(1, 85);
    int line = 0;
    int i;
    FILE *fpin = fopen("D:\\Microsoft-VS-Code-Cpp-Programs\\AlgorithmAndStruct\\06\\string.in", "r");
    FILE *fpout = fopen("D:\\Microsoft-VS-Code-Cpp-Programs\\AlgorithmAndStruct\\06\\string.out", "w");

    if (fpin == NULL)
        exit(-1);
    if (fpout == NULL)
        exit(-1);
    scanf("%s", inputString);
    while (fgets(tempLine, 81, fpin) != NULL)
    {
        line++;
        int flag = 1;
        for (i = 0; tempLine[i] != '\0'; i++)
        {
            if (isMatched(tempLine, i, inputString, output))
            {
                if (flag)
                    fprintf(fpout, "%d:", line);
                else
                    fprintf(fpout, ",");
                fprintf(fpout, "%s", output);
                flag = 0;
            }
        }
        if (!flag)
            fprintf(fpout, "\n");
    }

    fclose(fpin);
    fclose(fpout);
    return 0;
}
