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

void print()
{
	struct Node *temp=head;
	printf("List is : ");
	while(temp!=NULL)
	{
		printf(" [%d] ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void deleteNth(int n)
{
	struct Node *temp1=head;
	if(n==1)
	{
		head=temp1->next;
		free(temp1);
		return;
	}

	int i;
	for(i=0;i<n-2;i++)
		temp1=temp1->next;
	
	struct Node *temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
}

int main()
{
	head=NULL;
	insert(40,1);
	insert(30,2);
	insert(20,1);
	insert(10,1);

	print();
	deleteNth(4);
	print();
	deleteNth(1);
	print();
	deleteNth(2);
	print();

	return 0;
}