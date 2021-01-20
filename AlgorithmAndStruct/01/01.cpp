#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int num;
    struct Node *last;
    struct Node *next;
};

//Get the length of the list.
int GetLength(void)
{
    int n;
    cin >> n;

    //check if legal
    if (n <= 0)
    {
        cout << "The length must be positive." << endl;
        return -1;
    }
    return n;
}

//create a new list
struct Node *CreateNew(int n)
{
    if (n <= 0)
    {
        cout << "Length is illegal." << endl;
        return NULL;
    }

    struct Node *head = NULL, *p1 = NULL, *p2 = NULL, *p3 = NULL;
    for (int i = 0; i < n; i++)
    {
        p1 = (struct Node *)malloc(sizeof(struct Node));
        cin >> p1->num;
        if (i == 0)
        {
            head = p1;
            p1->last = NULL;
            p3 = p1;
        }
        else
        {
            if (i > 1)
            {
                p2->last = p3;
                p3 = p3->next;
            }
            p2->next = p1;
        }
        p2 = p1;
    }
    p2->last = p3;
    p2->next = head;
    head->last = p2;

    //check if the head pointer is null
    if (head == NULL)
    {
        cout << "There is something wrong creating list." << endl;
    }
    return head;
}

//print all data in the console (in "next" way)
void PrintData(struct Node *head)
{
    if (head == NULL)
    {
        cout << "Head pointer is null." << endl;
        return;
    }

    struct Node *temp = head;
    do
    {
        cout << temp->num << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

//delete one object
void DeleteObject(struct Node *object)
{
    object->last->next = object->next;
    object->next->last = object->last;
}

//insert object in front of position
void InsertForehead(struct Node *position, struct Node *object)
{
    object->next = position;
    object->last = position->last;
    position->last->next = object;
    position->last = object;
}

//sort the list from small to big
struct Node *SortList(struct Node *head)
{
    //check if legal
    if (head == NULL)
    {
        cout << "Head pointer is null." << endl;
        return NULL;
    }

    struct Node *p1 = NULL, *p2 = NULL;
    bool finish = false;
    p2 = p1 = head;
    do
    {
        p2 = p2->next;
        if (p2 == head->next)
        {
            finish = !finish;
        }
    } while (((p1->num) >= (p2->num)) && finish);
    head = p1->next; //change head pointer
    DeleteObject(p1);
    InsertForehead(p2, p1);
    if (head->last->num < head->num)
    {
        head = head->last;
    }
    return head;
}

int main(int argc, const char **argv)
{
    int length = GetLength();
    struct Node *list = CreateNew(length);
    list = SortList(list);
    PrintData(list);
    return 0;
}