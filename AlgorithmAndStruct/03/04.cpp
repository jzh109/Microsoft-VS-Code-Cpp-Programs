#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    ATOM,
    LIST
} ElemTag;

typedef struct GLNode
{
    ElemTag tag;
    union
    {
        char atom;
        struct
        {
            struct GLNode *hp, *tp;
        } ptr;
    };
} * GList;

//if two GList is equal to each other
bool equal(GList a, GList b)
{
    //if the pointer is NULL
    if (a == NULL && b == NULL)
    {
        return true;
    }
    else if (a == NULL || b == NULL)
    {
        return false;
    }
    if (a->tag == ATOM && b->tag == ATOM)
    {
        if (a->atom == b->atom)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (a->tag == LIST && b->tag == LIST)
    {
        if (equal(a->ptr.hp, b->ptr.hp) && equal(a->ptr.tp, b->ptr.tp))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

//divide substring into head SUBGList and tail SUBGList
void divide(char *s, char *hstr)
{
    int i, j, k, r;
    char rstr[100];

    i = j = k = 0;
    //get head SUBGList
    while (s[i] && (s[i] != ',' || k))
    {
        if (s[i] == '(')
        {
            k++;
        }
        else if (s[i] == ')')
        {
            k--;
        }
        if (s[i] != ',' || k)
        {
            hstr[j] = s[i];
            i++;
            j++;
        }
    }

    hstr[j] = '\0';
    if (s[i] == ',')
    {
        i++;
    }

    r = 0;
    //get tail SUBGList
    while (s[i])
    {
        rstr[r] = s[i];
        r++;
        i++;
    }
    rstr[r] = '\0';
    strcpy(s, rstr);
}

//create a GList
GLNode *GLCreate(char *s)
{
    GLNode *p, *q, *r, *head;
    char substr[100], hstr[100];
    int len;

    len = strlen(s);
    if (!strcmp(s, "()") || !len)
    {
        head = NULL;
    }
    else if (len == 1)
    {
        head = (GLNode *)malloc(sizeof(GLNode));
        if (!head)
            return NULL;
        head->tag = ATOM;
        head->atom = *s;
    }
    else
    {
        head = (GLNode *)malloc(sizeof(GLNode));
        if (!head)
            return NULL;
        head->tag = LIST;
        p = head;
        s++;
        strncpy(substr, s, len - 2);
        substr[len - 2] = '\0';
        do
        {
            divide(substr, hstr);
            r = GLCreate(hstr);
            p->ptr.hp = r;
            q = p;
            len = strlen(substr);
            //if tail GList can be constructed (substring is NOT NULL)
            if (len > 0)
            {
                p = (GLNode *)malloc(sizeof(GLNode));
                if (!p)
                    return NULL;
                p->tag = LIST;
                q->ptr.tp = p;
            }
        } while (len > 0);
        q->ptr.tp = NULL;
    }
    return head;
}

int main(int argc, const char *argv[])
{
    char s1[100], s2[100];
    std::cin >> s1;
    std::cin >> s2;
    GList a = GLCreate(s1);
    GList b = GLCreate(s2);
    if (equal(a, b))
    {
        std::cout << "1" << std::endl;
    }
    else
    {
        std::cout << "0" << std::endl;
    }
    return 0;
}