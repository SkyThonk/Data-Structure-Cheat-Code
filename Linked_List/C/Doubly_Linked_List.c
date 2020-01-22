#include<stdio.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head,*last;

void InsertLast(int data);
void Display();

int main()
{
    InsertLast(3);
    InsertLast(6);
    InsertLast(9);
    printf("\nList: ");
    Display();
    return 0;
}

void InsertLast(int data)
{
    struct Node * t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        head = t;
        last = t;
        t->prev=NULL;
        t->data=data;
        t->next=NULL;
    }
    else
    {
        t->prev=last;
        last->next=t;
        t->data=data;
        t->next=NULL;
        last = t;
    }
}

void Display()
{
    struct Node *p;
    p=head;
    while(p)
    {
        printf("\t%d",p->data);
        p = p->next;
    }
}
