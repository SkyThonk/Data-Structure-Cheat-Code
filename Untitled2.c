#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *Insert(struct Node *head, int data)
{
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = data;
	if (head == NULL){
			head = p;
			p->next = NULL;
	}
	else{
			p->next = head;
			head = p;
		}

	return head;
}

void display(struct Node *head)
{
	struct Node *temp = head;
	printf("\n\nDisplay: ");
	while(temp!=NULL)
	{
		printf("\t%d",temp->data);
		temp = temp->next;
	}
}

struct Node * Ndelete(struct Node *head,int pos)
{
	struct Node *p=head;
	struct Node *q=NULL;
	int x,t,sum=0,r,i;
          if(pos==1)
	{
		x = p->data;
		t = x;
		while(x!=0)
		{
			r = x%10;
			sum = sum + (r*r*r);
			x = x/10;
		}
		if(sum!=t)
		{
			head = head->next;
			free(p);
		}

	}
	else
	{
		for(i=0;i<pos-1&&p;i++)
		{
			q = p;
			p = p->next;
		}
		x = p->data;
		t = x;
		while(x!=0)
		{
			r = x%10;
			sum = sum + (r*r*r);
			x = x/10;
		}
		if(t!=sum)
		{
			q->next = p->next;
			free(p);

		}

	}
	return head;
}
int main()
{
	struct Node *head = NULL;
	head = Insert(head,153);
	head = Insert(head,20);
	head = Insert(head,30);
	display(head);
	head = Ndelete(head,1);
	display(head);
	return 0;
}

