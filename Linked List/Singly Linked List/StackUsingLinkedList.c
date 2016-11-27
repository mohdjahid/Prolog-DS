#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *top;

void push(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=top;
	top=temp;
}

int pop()
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp=top;
	if(temp==NULL)
	{
		printf("Error:Stack is underflow\n");
		return -1;
	}
	top=temp->next;
	return (temp->data);
}

int main()
{
	top=NULL;
	int data,option;

	do
	{
		printf("----Chose An Option-----\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:	printf("Enter the data for stack : ");
					scanf("%d",&data);
					push(data);
					break;
			case 2:	data=pop();
					printf("Poped data is : %d\n",data);
					break;
			case 3: printf("Thankyou Almighty God");
		}
	}
	while (option!=3);
				
}