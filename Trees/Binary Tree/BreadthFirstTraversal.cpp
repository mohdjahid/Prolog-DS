#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

struct Node * getNewNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct Node * insert(struct Node *root,int data)
{
	if(root==NULL)
		root=getNewNode(data);
	else if(data<=root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);

	return root;
}

void levelOrderTraversal(Node *root)
{
	if( root==NULL) return ;
	
	queue<Node*> Q;
	Q.push(root);
	while( !Q.empty() )
	{
		Node *current=Q.front();
		cout<<Q.front()->data<<" ";

		if(current->left!=NULL) Q.push(current->left);
		if(current->right!=NULL) Q.push(current->right);
		Q.pop();
	}
}

int main()
{
	Node *root=NULL;	
	root=insert(root,12);
		 insert(root,5);
		 insert(root,15);
		 insert(root,3);
		 insert(root,7);
		 insert(root,13);
		 insert(root,17);
		 insert(root,1);
		 insert(root,9);
		 insert(root,19);

	levelOrderTraversal(root);
}
