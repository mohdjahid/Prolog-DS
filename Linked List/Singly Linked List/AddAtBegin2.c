#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

void insert(struct Node **head,int x)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=*head;
	*head=temp;
}

void print(struct Node *temp)
{
	printf("List is : ");
	while(temp!=NULL)
	{
		printf(" [%d] ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	struct Node *head=NULL;
	int i,n,x;
	printf("Enter the numbers of Elements : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the Element Number %d : ",i+1);
		scanf("%d",&x);
		insert(&head,x);
		print(head);
	}

	return 0;
}
