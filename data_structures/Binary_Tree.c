/*
Concepts: Data structure starting with Binary Trees
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node
{
	int publicValue;
	int privateValue;
	node *left;
	node *right;
	node *neighbour;
	node *parent;
};

node* newNode(int,int);
node * insertNode(node *,int,int);
node * deleteNode(node *);
int lookup(node *);
int size(node *);

int main()
{
	int i,numNodes;
	node *root = NULL;
	node *newNodePtr = NULL;

	/* Inserting a node for the first time, changes the root from NULL to the root of the tree 
	   Right now, by default the first node is the root of the tree. Root remains constant now onwards*/
	
	root = insertNode(root,0,10);
	
	for(i=1;i<10;i++)
	{
		newNodePtr = insertNode(root,i,10);
	}
	numNodes = size(root);
	printf("Number is nodes in a tree: %d\n",numNodes);

	return 0;
}

node* newNode(int privateValue, int publicValue)
{
	node *newNodePtr;
	newNodePtr = (node*)malloc(sizeof(node));
	newNodePtr ->privateValue = privateValue;
	newNodePtr ->publicValue = publicValue;
	newNodePtr ->left = NULL;
	newNodePtr ->right = NULL;
	newNodePtr ->neighbour = NULL;
	newNodePtr ->parent = NULL;
	return newNodePtr	;
}

//Iterative Method to insert new node. 
node * insertNode(node* root,int privateValue, int publicValue)
{
	node *newNodePtr;
	node *movePtr;
	node *currentPtr;

	newNodePtr = newNode(privateValue,publicValue);

	if(root == NULL)
	{
		return(newNodePtr);	
	}	
	else
	{
		currentPtr = root;

		while(currentPtr != NULL)
		{
				if(currentPtr->privateValue > newNodePtr->privateValue )
				{
					movePtr = currentPtr->left;
					if(movePtr == NULL)
					{
						currentPtr->left = newNodePtr;
						// movePtr = newNodePtr;
						// VERIFY
						return newNodePtr;
					}
					currentPtr = movePtr; 
				}
				else
				{	
					movePtr = currentPtr->right;
					if(movePtr == NULL)
					{
						currentPtr->right = newNodePtr;
						// movePtr = newNodePtr;
						// VERIFY
						return newNodePtr;
					}
					currentPtr = movePtr;
				}
			}
		}
}
int size(node *root){
	if (	root==NULL)
		return 0;
	else
		return(size(root->left)+1+size(root->right));
}