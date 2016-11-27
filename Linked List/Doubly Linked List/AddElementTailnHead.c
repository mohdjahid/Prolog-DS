#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node *head;

struct Node * getNewNode(int x)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=temp->prev=NULL;
	return temp;
}

void insertAtHead(int x)
{
	struct Node *newNode=getNewNode(x);
	if(head==NULL)
	{
		head=newNode;
		return;
	}
	newNode->next=head;
	head->prev=newNode;
	head=newNode;
}

void insertAtTail(int x)
{
	struct Node *newNode=getNewNode(x);
	if(head==NULL)
	{
		head=newNode;
		return;
	}
	struct Node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->prev=temp;
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

void printReverse()
{
	struct Node *temp=head;
	printf("Reverse List is : ");
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	while(temp!=NULL)
	{
		printf(" [%d] ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}

int main()
{
	head=NULL;
	insertAtHead(10);
	print();
	insertAtHead(20);
	print();
	insertAtHead(30);
	print();
	insertAtHead(40);
	print();
	insertAtTail(50);
	print();
	printReverse();

	return 0;
}
