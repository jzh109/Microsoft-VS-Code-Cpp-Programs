#include "malloc.h"
#include <stdio.h> //�����������������
#define LEN sizeof(struct infomation)
#define NULL 0

struct infomation
{
    long num;
    int score;
    struct infomation *next;
};

struct infomation *create(void)
{
    struct infomation *head, *p1, *p2;
    int n = 0;
    p1 = p2 = (struct infomation *)malloc(LEN);
    head = NULL;
    while (n < 10)
    {
        scanf("%ld %d", &p1->num, &p1->score);
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct infomation *)malloc(LEN);
    }
    p2->next = NULL;
    return (head);
}
struct infomation *order(struct infomation *head)
{
    struct infomation *p1, *temp, *p2, *pa1, *pa2, *pb1, *pb2;
    long min;
    p1 = temp = p2 = pa1 = pa2 = pb1 = pb2 = NULL;

    {
        min = head->num;
        p2 = pa2 = head->next;
        while (p2 != NULL) //ȷ����Сֵ
        {
            if (p2->num < min)
                min = p2->num;
            p2 = p2->next;
        }
        p2 = head->next;
        while (p2->num != min) //ȷ����Сֵ���ڵĽṹ���ַp2
            p2 = p2->next;
        while (pb1->next != p2) //ȷ����Сֵ���ڵĽṹ��ǰһ���ַpb1
            pb1 = pb1->next;
        pb2 = p2->next, pa2 = head->next; //ȷ����Сֵ���ڽṹ���һ��ĵ�ַpb2��δ����ڶ����ַpa2
        temp = head;
        head = p2;
        p2 = temp;
        head->next = pa2, pb1->next = p2, p2->next = pb2;
    }
    p1 = head->next;
    while (p1->next != NULL)
    {
        min = p1->num;
        while (p2 != NULL) //ȷ����Сֵ
        {
            if (p2->num < min)
                min = p2->num;
            p2 = p2->next;
        }
        p2 = p1->next;
        while (p2->num != min) //ȷ����Сֵ���ڵĽṹ���ַp2
            p2 = p2->next;
        if (p1 != head)
        {
            while (pa1->next != p1) //ȷ���ź�������һ���ַpa1
                pa1 = pa1->next;
            while (pb1->next != p2) //ȷ����Сֵ���ڽṹ��ǰһ���ַpb1
                pb1 = pb1->next;
            pa2 = p1->next, pb2 = p2->next; //ȷ����Сֵ���ڽṹ���һ��ĵ�ַpb2��δ����ڶ����ַpa2
            temp = p1;
            p1 = p2;
            p2 = temp; //��λ�ú�p1�洢��Сֵ���ڽṹ���ַ��p2�洢ԭ��һ��δ����ṹ���ַ
            pa1->next = p1, p1->next = pa2, pb1->next = p2, p2->next = pb2;
            p1 = pa1;
            p2 = p1->next;
        }
        return head;
    }
}
void insert(struct infomation *head, struct infomation *in)
{
    struct infomation *p, *p1;
    p = head;
    p1 = p->next;
    while (p->next != NULL)
    {
        if (p->num < 1005)
        {
            p->next = in;
            in->next = p1;
            break;
        }
        p = p->next;
    }
}
void print(struct infomation *head)
{
    struct infomation *p;
    p = head;
    while (p != NULL)
    {
        printf("%ld,%d\n", p->num, p->score);
        p = p->next;
    }
}
int main()
{
    struct infomation *head, *in;
    head = create();
    head = order(head);
    print(head);
    //in = (struct infomation*)malloc(LEN);
    //scanf_s("%d %d", &in->num, &in->score);
    //insert(head, in);
    //print(head);
    return 0;
}
