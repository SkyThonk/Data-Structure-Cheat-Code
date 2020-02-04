#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *InsertTop(struct Node *head, int data);
struct Node *InsertLast(struct Node *head, int data);
void Display(struct Node *head);
void DisplayReverse(struct Node *head);
struct Node *InsertPos(struct Node *head, int data, int pos);
int main()
{
    int f = 1, data, num, pos;
    struct Node *head = NULL;

    do
    {
        printf("\n\n----------------------------------------------------------------------");
        printf("\n| 1 -> For insert at top of doubly Linked List");
        printf("\n| 2 -> For insert at Last of doubly Linked List");
        printf("\n| 3 -> Display doubly Linked List");
        printf("\n| 4 -> Display from reverse side of doubly Linked List");
        printf("\n| 5 -> For insert node at specific position of doubly Linked List");
        printf("\n| 6 -> Exit");
        printf("\n----------------------------------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
        {
            printf("\n#######################################################################");
            printf("\nEnter the number: ");
            scanf("%d", &data);
            printf("#######################################################################");
            head = InsertTop(head, data);
            break;
        }
        case 2:
        {
            printf("\n#######################################################################");
            printf("\nEnter the number: ");
            scanf("%d", &data);
            printf("#######################################################################");
            head = InsertLast(head, data);
            break;
        }
        case 3:
        {
            printf("\n#######################################################################");
            printf("\nDisplay:    ");
            Display(head);
            printf("\n#######################################################################");
            break;
        }
        case 4:
        {
            printf("\n#######################################################################");
            printf("\nDisplay:    ");
            DisplayReverse(head);
            printf("\n#######################################################################");
            break;
        }
        case 5:
        {
            printf("\n#######################################################################");
            printf("\nEnter the number and position:\n ");
            scanf("%d", &data);
            scanf("%d", &pos);
            printf("#######################################################################");
            head = InsertPos(head, data, pos);
            break;
        }
        case 6:
        {
            f = 0;
            break;
        }
        }

    } while (f);
    return 0;
}

struct Node *InsertTop(struct Node *head, int data)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->prev = NULL;
    if (head == NULL)
    {
        head = t;
        t->next = NULL;
    }
    else
    {
        t->next = head;
        head->prev = t;
        head = t;
    }
    return head;
}

struct Node *InsertLast(struct Node *head, int data)
{
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    if (head == NULL)
    {
        t->prev = NULL;
        head = t;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
    }
    return head;
}

void Display(struct Node *head)
{
    struct Node *p;
    p = head;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

void DisplayReverse(struct Node *head)
{
    struct Node *p;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p)
    {
        printf("%d\t", p->data);
        p = p->prev;
    }
}

struct Node *InsertPos(struct Node *head, int data, int pos)
{
    struct Node *p, *t;
    int i;
    p = head;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    if (pos == 0)
    {
        printf("\nInvalid Position");
    }
    else if (pos == 1)
    {
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else if (pos > 1)
    {
        for (i = 1; i < pos - 1 && p->next; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }

    return head;
}
