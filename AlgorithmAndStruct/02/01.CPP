#include <iostream>
#include <stdlib.h>
#include <string>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char SElemType;

typedef struct
{
    SElemType *top;
    SElemType *base;
    int stacksize;
} sqStack;

void InitStack(sqStack &s)
{
    s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s.base)
        exit(0);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
}

void Push(sqStack &s, SElemType e)
{
    if (s.top - s.base >= s.stacksize)
    {
        s.base = (SElemType *)realloc(s.base, ((s.stacksize + STACKINCREMENT) * sizeof(SElemType)));
        if (!s.base)
            exit(0);
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREMENT;
    }
    *s.top = e;
    s.top++;
}

bool Empty(sqStack &s)
{
    return s.base == s.top;
}

void Pop(sqStack &s)
{
    if (Empty(s))
        exit(0);
    s.top--;
}

int main()
{
    std::string inputString;
    getline(std::cin, inputString);

    sqStack s;
    InitStack(s);
    int res = 0;
    for (int p = 0; inputString[p] != '@'; p++)
    {
        if (inputString[p] == '(')
        {
            Push(s, '(');
        }
        else if (inputString[p] == ')' && !Empty(s))
        {
            Pop(s);
            res++;
        }
    }
    if (res != 0 && Empty(s))
        std::cout << res << std::endl;
    else
        std::cout << "no" << std::endl;
    return 0;
}