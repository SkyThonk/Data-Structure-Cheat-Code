#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st);
void push(struct Stack *st, int data);
void display(struct Stack st);
int pop(struct Stack *st);
int isEmpty(struct Stack *st);
int isFull(struct Stack *st);
int StackTop(struct Stack *st);
int peek(struct Stack st, int pos);

int main()
{
    int n, i;
    struct Stack st;
    create(&st);
    printf("\nEnter the elements of stack:\n");
    for(i =0;i<st.size;i++)
    {
        scanf("%d",&n);
        push(&st,n);

    }
    display(st);

    printf("\nPop item: %d",pop(&st));
    printf("\nPop item: %d",pop(&st));
    display(st);
    printf("\n\nIs stack Empty: %d",isEmpty(&st));
    printf("\n\nIs stack Full: %d",isFull(&st));
    printf("\n\nStack Top: %d",StackTop(&st));
    printf("\n\nPeek: %d",peek(st,3));
    return 0;
}

void create(struct Stack *st)
{
    printf("Enter the size of stack: ");
    scanf("%d",&st->size);
    st->top =-1;
    st->s= (int *)malloc(st->size*sizeof(int));
}

void push(struct Stack *st, int data)
{
    if(st->top==st->size-1)
        printf("\nStack Overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = data;
    }
}

void display(struct Stack st)
{
    int i;
    printf("\nStack Element: ");
    for(i=0;i<=st.top;i++)
    {
        printf("\t%d",st.s[i]);
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if(st->top==-1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(struct Stack *st)
{
    if(st->top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *st)
{
    if(st->top==st->size -1)
        return 1;
    else
        return 0;
}

int StackTop(struct Stack *st)
{
    if(st->top==-1)
        return -1;
    else
        return st->s[st->top];
}
int peek(struct Stack st, int pos)
{
    int x = -1;
    if(st.top - pos + 1<0)
        printf("Invalid Position");
    else
        x = st.s[st.top - pos +1];
    return x;
}
//test