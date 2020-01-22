#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}*head, *last;

void InsertLast(int data);
void Insert(int pos,int data);
void display();
int NodeCount();
int NodeSum();
int Delete(int pos);
void Reverse();
int NodeMax();

int main()
{
    int nc,nsum,dn;

    InsertLast(1);
    InsertLast(2);
    InsertLast(3);
    InsertLast(4);
    InsertLast(5);
    display();

    printf("\n");

    Insert(2,24);
    Insert(5,121);
    Insert(0,11);
    display();

    printf("\n");

    nc = NodeCount();
    printf("\nTotal Numbers of node: %d\n",nc);

    printf("\n\n");

    nsum = NodeSum();
    printf("Total sum of each node: %d\n",nsum);

    printf("\n\n");

    dn = Delete(3);
    printf("Deleted Node: %d\n",dn);
    printf("After Delete: ");
    display();

    printf("\n\nAfter Reverse: ");
    Reverse();
    display();

    printf("\n\n");
    printf("Max Number is Linked List: %d",NodeMax());
    return 0;
}

///Insertion in a linked list at last position
void InsertLast(int data)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    if(head==NULL)
    {
        head = t;
        last = t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}

///Insertion in a linked node at any given position
void Insert(int pos,int data)
{
    int i;
    struct Node *p, *t;
    if(pos==0)
    {
        t= (struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        t->next = head;
        head = t;
    }
    else if(pos>0)
    {
        p = head;
        for(i=0;i<pos-1&&p;i++)
        {
            p=p->next;
        }
        if(p)
        {
        t= (struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        t->next = p->next;
        p->next=t;
        }
    }
}

///function for displaying nodes
void display()
{
    struct Node *p;
    p = head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

///function for counting the numbers of nodes on a linked list
int NodeCount()
{
    struct Node *p;
    int c = 0;
    p = head;
    while(p)
    {
        c++;
        p = p->next;
    }

    return c;
}

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
