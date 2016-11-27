#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *front,*rear;

void enQueue(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
		return ;
	}
	rear->next=temp;
	rear=temp;
}

void deQueue()
{
	struct Node *temp=front;
	
	if(front==NULL)
	{
		printf("Error:Queue is underflow\n");
		return;
	}
	if(front==rear)
		front=rear=NULL;
	else
		front=front->next;

	free(temp);
}

int isEmpty()
{
	return (front==NULL)?1:0;
}

int peek()
{
	
	return (isEmpty())? printf("Queue is Empty\n"),-1:front->data;
	
}



int main()
{
	front=rear=NULL;
	int data,option;

	do
	{
		printf("----Chose An Option-----\n");
		printf("1. EnQueue\n");
		printf("2. DeQueue\n");
		printf("3. Front/Peek\n");
		printf("4. IsEmpty\n");
		printf("5. Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:	printf("Enter the data for stack : ");
					scanf("%d",&data);
					enQueue(data);
					break;
			case 2:	deQueue();
					break;
			case 3: data=peek();
					printf("Element : %d\n",data);
					break;
			case 4: isEmpty()?printf("Queue is Empty\n"):printf("Queue is not Empty\n");
					break;
			case 5: printf("Thankyou Almighty God");
		}		
	}
	while (option!=5);
				
}