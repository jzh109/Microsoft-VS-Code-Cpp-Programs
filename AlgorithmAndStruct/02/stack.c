#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10

typedef int SElemType;

typedef struct
{
    SElemType *top;
    SElemType *base;
    int stacksize;
} sqStack;

void InitStack(sqStack *s)
{
    s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s->base)
        exit(0);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

void Push(sqStack *s, SElemType e)
{
    // if (s.top - s.base >= s.stacksize)
    // {
    //     s.base = (SElemType *)realloc(s.base, ((s.stacksize + STACKINCREMENT) * sizeof(SElemType)));
    //     if (!s.base)
    //         exit(0);
    //     s.top = s.base + s.stacksize;
    //     s.stacksize += STACKINCREMENT;
    // }
    *(s->top) = e;
    s->top++;
}

int Empty(sqStack *s)
{
    return s->base == s->top ? 1 : 0;
}

void Pop(sqStack *s, SElemType *e)
{
    if (Empty(s))
        exit(0);
    (s->top)--;
    *e = *(s->top);
}

int Full(sqStack *s)
{
    return s->top - s->base == s->stacksize ? 1 : 0;
}

int main()
{
    int order;
    sqStack s;
    InitStack(&s);
    while (scanf("%d", &order), order != -1)
    {
        if (order == 1)
        {
            SElemType data;
            scanf("%d", &data);
            Push(&s, data);
        }
        else if (order == 0 && !Empty(&s) && !Full(&s))
        {
            SElemType data;

            Pop(&s, &data);
            printf("%d ", data);
        }
        else
        {
            printf("error ");
        }
    }

    return 0;
}