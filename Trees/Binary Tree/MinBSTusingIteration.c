#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

struct BstNode * getNewNode(int data)
{
	struct BstNode *temp=(struct BstNode *)malloc(sizeof(struct BstNode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct BstNode * insert(struct BstNode *root,int data)
{
	if(root==NULL)
		root=getNewNode(data);
	else if(data<=root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);

	return root;
}

int getMin(struct BstNode *root)
{
	if(root==NULL)
	{
		printf("Tree is Empty\n");
		return -1;
	}
	while(root->left!=NULL)
		root=root->left;

	return root->data;
}

int main()
{
	struct BstNode *root=NULL;
	printf("Min Element : %d\n",getMin(root));
	root=insert(root,20);
		 insert(root,15);
		 insert(root,17);
		 insert(root,25);
		 insert(root,22);
		 insert(root,12);
	printf("Min Element : %d\n",getMin(root));
}