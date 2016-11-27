#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

using namespace std;

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

BstNode * Find(BstNode *root,int data)
{
	if( root==NULL) return NULL;
	
	queue<BstNode*> Q;
	Q.push(root);
	while( !Q.empty() )
	{
		BstNode *current=Q.front();
		if(current->data==data)
			return current;

		if(current->left!=NULL) Q.push(current->left);
		if(current->right!=NULL) Q.push(current->right);
		Q.pop();
	}
	return NULL;
}

struct BstNode * FindMax(struct BstNode *root)
{
	if(root->right==NULL)
		return root;

	return FindMax(root->right);
}

BstNode * getPredecer(BstNode *root,int data)
{
	BstNode *current=Find(root,data);
	if(current==NULL) return NULL;
	if(current->left!=NULL)
		return FindMax(current->left); // Case 1: Having Right subTree
	else //Case 2: No right subTree
	{
		BstNode *predecer=NULL;
		BstNode *ancestor=root;
		while(current!=ancestor)
		{
			if(current->data>ancestor->data)
			{
				predecer=ancestor;
				ancestor=ancestor->right;
			}
			else
				ancestor=ancestor->left;
		}
		return predecer;
	}
}

int main()
{
	struct BstNode *root=NULL;
	root=insert(root,15);
		 insert(root,10);
		 insert(root,20);
		 insert(root,8);
		 insert(root,12);
		 insert(root,17);
		 insert(root,25);
		 insert(root,6);
		 insert(root,11);
		 insert(root,16);
		 insert(root,27);

	cout<<"Enter Value to find Predecer : ";
	int data;
	cin>>data;
	BstNode *predecer=getPredecer(root,data);
	if(predecer!=NULL)
		printf("%d",predecer->data);
	else
		printf("No Inorder Predecer");
}