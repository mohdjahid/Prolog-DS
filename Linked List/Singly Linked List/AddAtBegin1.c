#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node *head;

void insert(int x)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	head=temp;
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

int main()
{
	head=NULL;
	int i,n,x;
	printf("Enter the numbers of Elements : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the Element Number %d : ",i+1);
		scanf("%d",&x);
		insert(x);
		print();
	}

	return 0;
}
