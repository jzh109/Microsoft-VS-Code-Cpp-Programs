#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char name[10];
    int age;
    Person *next;
};

Person *create(void)
{
    Person *p1, *p2, *head;
    p1 = p2 = (Person *)malloc(sizeof(Person));
    for (int i = 0; i < 3; i++)
    {
        scanf("%s%d", p1->name, &p1->age);
        if (i == 0)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (Person *)malloc(sizeof(Person));
    }
    p2->next = NULL;
    return head;
}

void print(Person *begin)
{
    Person *now = begin;
    while (now != NULL)
    {
        printf("%s %d", now->name, now->age);
        now = now->next;
    }
}

int main()
{
    Person *begin = create();
    print(begin);
    return 0;
}