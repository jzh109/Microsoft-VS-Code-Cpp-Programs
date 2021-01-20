#include <stdio.h>
#include "malloc.h"
#define LEN sizeof(struct infomation)
#define NULL 0

struct infomation
{
    long num;
    int score;
    struct infomation *next;
};

struct infomation* create(void)
{
    struct infomation* head, * p1, * p2;
    int n = 0; 
    p1 = p2 = (struct infomation*)malloc(LEN);
    head = NULL;
    while (n<10)
    {
    	scanf("%ld %d", &p1->num, &p1->score);
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct infomation*)malloc(LEN);
    }
    p2->next = NULL;
    return(head);
}
void print(struct infomation* head)
{
    struct infomation* p;
    p = head;
    while (p != NULL)
    {
        printf("%ld,%d\n", p->num, p->score);
        p = p->next;
    }
}
int main()
{
    struct infomation* head;
    head = create();
    print(head);
    return 0;
}
