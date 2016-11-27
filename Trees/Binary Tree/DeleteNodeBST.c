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

struct BstNode * getMinAddres(struct BstNode *root)
{
	if(root->left==NULL)
		return root;

	return getMinAddres(root->left);
}

struct BstNode * deleteNode(struct BstNode *root,int data)
{
	if (root==NULL) //Tree Is Empty
	{
		printf("Not Found\n");
		return root;
	}

	else if( data < root->data ) // Go to left-SubTree
		root->left=deleteNode(root->left,data);
	else if( data > root->data ) // Go to right-SubTree
		root->right=deleteNode(root->right,data);
	else // Founded Means data==root->data, It will be deleted
	{
						// Consider 3 Cases
		if( root->left==NULL && root->right==NULL )//case 1:No Child or Leaf Node
		{
			root=NULL;  // Set Reference as NULL
			free(root); // Delete Node From Heap
		}	
		else if( root->right==NULL )//case 2:Node Having 1 Child, having left Child
			{
				struct BstNode *temp=root;
				root=root->left; // Assinging next left Child
				free(temp);      // Delete Node From Heap
			}
			else if( root->right==NULL )//case 2:Node Having 1 Child, having right Child
			{
				struct BstNode *temp=root;
				root=root->right; // Assinging next right Child
				free(temp);      // Delete Node From Heap
			}
			else // Case 3: Node having both Children
			{
				struct BstNode *temp=getMinAddres(root->right); // Find Address of Min Node From right subTree
				root->data=temp->data;
				root->right=deleteNode(root->right,data); //Now Delete the duplicated Node from right subTree
			}
	}
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

int getMax(struct BstNode *root)
{
	if(root==NULL)
	{
		printf("Tree is Empty\n");
		return -1;
	}
	while(root->right!=NULL)
		root=root->right;

	return root->data;
}


int main()
{
	struct BstNode *root=NULL;
	root=insert(root,20);
		 insert(root,5);
		 insert(root,15);
		 insert(root,3);
		 insert(root,7);
		 insert(root,13);
		 insert(root,17);
		 insert(root,1);
		 insert(root,9);
		 insert(root,19);

	printf("Min Element : %d\n",getMin(root));
	printf("Max Element : %d\n",getMax(root));
	deleteNode(root,12);
	printf("Min Element : %d\n",getMin(root));
	printf("Max Element : %d\n",getMax(root));
	
}