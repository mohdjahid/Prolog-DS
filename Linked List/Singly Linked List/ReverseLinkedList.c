#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node *head;

void insert(int data,int n)
{
	struct Node *temp1=(struct Node *)malloc(sizeof(struct Node));
	temp1->data=data;
	temp1->next=NULL;

	if(n==1)
	{
		temp1->next=head;
		head=temp1;
		return ;
	}

	struct Node *temp2=head;
	int i;
	for(i=0;i<n-2;i++)
		temp2=temp2->next;
	
	temp1->next=temp2->next;
	temp2->next=temp1;
}

void printForward(struct Node *temp)
{
	if(temp==NULL)
	{
		printf("\n");
		return ;
	}
	printf("%d ",temp->data);
	printForward(temp->next);
}

void printReverse(struct Node *temp)
{
	if(temp==NULL)
	{
		return ;
	}
	printReverse(temp->next);
	printf("%d ",temp->data);
}

void reverse(struct Node *p)
{
	if(p->next==NULL)
	{
		head=p;
		return;
	}
	reverse(p->next);
	struct Node *q=p->next;
	q->next=p;
	p->next=NULL;
}

int main()
{
	head=NULL;
	insert(40,1);
	insert(30,2);
	insert(20,1);
	insert(10,1);

	printf("List : ");
	printForward(head);

	printf("Reverse List : ");
	printReverse(head);
	
	reverse(head);
	printf("\nList : ");
	printForward(head);

	return 0;
}