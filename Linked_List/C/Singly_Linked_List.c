#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *InsertTop(struct Node *head, int data);
struct Node *InsertLast(struct Node *head, int data);
struct Node *InsertPos(struct Node *head, int pos, int data);
void Display(struct Node *head);
int NodeCount(struct Node *head);
/*
int NodeSum();
int Delete(int pos);
void Reverse();
int NodeMax();*/

int main()
{
    int f = 1, num, data, pos;
    struct Node *head;
    head = NULL;

    do
    {
        printf("\n\n===============================================================\n");
        printf("|| 1 -> For Insert node at top of a linked list\n");
        printf("|| 2 -> For Insert node at last of a linked list\n");
        printf("|| 3 -> For Insert node at given position of a linked list\n");
        printf("|| 4 -> For Display linked list\n");
        printf("|| 5 -> For Counting the number of linked list node\n");
        printf("===============================================================");
        printf("\nEnter your choice: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
        {
            printf("\nEnter the data for linked list node: ");
            scanf("%d", &data);
            head = InsertTop(head, data);
            break;
        }
        case 2:
        {
            printf("\nEnter the data for linked list node: ");
            scanf("%d", &data);
            head = InsertLast(head, data);
            break;
        }
        case 3:
        {
            printf("\nEnter the data and position for linked list node: \n");
            scanf("%d", &data);
            scanf("%d", &pos);
            head = InsertPos(head, data, pos);
            break;
        }
        case 4:
        {
            Display(head);
            break;
        }
        case 5:
        {
            printf("\nTotal Number of Nodes: %d", NodeCount(head));
            break;
        }
        }

    } while (f != 0);

    return 0;
}

struct Node *InsertTop(struct Node *head, int data)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    if (head == NULL)
    {
        head = t;
        t->next = NULL;
    }
    else
    {
        t->next = head;
        head = t;
    }

    return head;
}

///Insertion in a linked list at last position
struct Node *InsertLast(struct Node *head, int data)
{
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    if (head == NULL)
    {
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
    }

    return head;
}

///Insertion in a linked node at any given position
struct Node *InsertPos(struct Node *head, int pos, int data)
{
    int i;
    struct Node *p, *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    if (pos <= 0)
    {
        printf("\nInvalid Position");
        return head;
    }
    else if (pos == 1)
    {
        t->next = head;
        head = t;
    }
    else
    {
        p = head;
        for (i = 1; i < pos - 1 && p->next; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

    return head;
}

///function for displaying nodes
void Display(struct Node *head)
{
    struct Node *p;
    p = head;
    printf("\nDisplay:  ");
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

///function for counting the numbers of nodes on a linked list
int NodeCount(struct Node *head)
{
    struct Node *p;
    int c = 0;
    p = head;
    while (p)
    {
        c++;
        p = p->next;
    }

    return c;
}
/*
///function for doing sum of each node
int NodeSum()
{
    struct Node *p;
    int sum = 0;
    p=head;

    while(p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

///function for deleting node from linked list at any given position
int Delete(int pos)
{
    struct Node *p, *q;
    int i,x;
    p = head;
    if(pos == 0)
    {
        head = head->next;
        x = p->data;
        free(p);
    }
    else
    {
        for(i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

///function for reversing linked list
void Reverse()
{
    struct Node *p, *q=NULL, *r=NULL;
    p=head;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    head = q;
}

///Similar to this you can create min function
int NodeMax()
{
    struct Node *p = head;
    int m = -32768;
    while(p)
    {
        if(p->data>m)
            m = p->data;
        p = p->next;
    }

    return m;
}
*/
