#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 50
#define _CRT_SECURE_NO_WARNINGS
typedef struct node
{
    char ch;
    int n;
    struct node *lchild, *rchild;
} BTnode, *BTREE;
struct code
{
    char ch;
    char a[10];
} code[MAXSIZE];

BTREE create_BT(int n);
void print(BTREE T);
void layer(BTREE T, char date[]);

BTREE create_BT(int n)
{
    BTREE p, T, p2;
    int i, j;
    p = (BTREE)malloc(sizeof(BTnode));
    p->lchild = NULL;
    p->rchild = NULL;
    p->n = 0;
    T = p;
    for (i = 0; i < n; i++)
    {
        for (j = 0; code[i].a[j] != '\0'; j++)
        {
            if (code[i].a[j] == '0')
            {
                if (p->lchild == NULL)
                {
                    p2 = p;
                    p = (BTREE)malloc(sizeof(BTnode));
                    p->lchild = NULL;
                    p->rchild = NULL;
                    p->n = 0;
                    p2->lchild = p;
                }
                else
                    p = p->lchild;
            }
            else if (code[i].a[j] == '1')
            {
                if (p->rchild == NULL)
                {
                    p2 = p;
                    p = (BTREE)malloc(sizeof(BTnode));
                    p->lchild = NULL;
                    p->rchild = NULL;
                    p->n = 0;
                    p2->rchild = p;
                }
                else
                    p = p->rchild;
            }
        }
        p->ch = code[i].ch;
        p = T;
    }
    return T;
}

void print(BTREE T)
{
    if (T != NULL)
    {
        print(T->lchild);
        print(T->rchild);
        printf("%d ", T->n);
    }
}

void layer(BTREE T, char date[])
{
    int i, len;
    BTREE p;
    p = T;
    p->n++;
    len = strlen(date);
    for (i = 0; i < len + 1; i++)
    {
        if (date[i] == '0')
        {
            if (p->lchild == NULL)
            {
                printf("%c", p->ch);
                i--;
                p = T;
                p->n++;
            }
            else
            {
                p = p->lchild;
                p->n++;
            }
        }
        else if (date[i] == '1')
        {
            if (p->rchild == NULL)
            {
                printf("%c", p->ch);
                i--;
                p = T;
                p->n++;
            }
            else
            {
                p = p->rchild;
                p->n++;
            }
        }
        else
            printf("%c", p->ch);
    }
}

int main()
{
    int i = 0, n;
    char date[100], c;
    BTREE T;
    FILE *file;
    file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("文件打开错误！\n");
        exit(0);
    }
    fgets(date, 100, file);
    fclose(file);
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        code[i].ch = getchar();
        getchar();
        gets(code[i].a);
    }
    T = create_BT(n);
    layer(T, date);
    printf("\n");
    print(T);
    free(T);
}