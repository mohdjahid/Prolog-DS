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

int search(struct BstNode *root,int data)
{
	if(root==NULL)
		return 0;
	else if(data==root->data)
			return 1;
		 else if(data<=root->data)
				 return search(root->left,data);
			  else 
				 return search(root->right,data);
}

int main()
{
	struct BstNode *root=NULL;
	root=insert(root,20);
		 insert(root,15);
		 insert(root,17);
		 insert(root,25);
		 insert(root,22);
		 insert(root,30);
	if(search(root,17))
		printf("Founded");
	else
		printf("Not Founded");

	if(search(root,23))
		printf("Founded");
	else
		printf("Not Founded");
}