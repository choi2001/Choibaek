#include <stdio.h>
#include<stdlib.h>

typedef struct tree {
	int data;
	struct tree* left;
	struct tree* right;
}tree;

tree* add(tree* root,int data)
{
	tree* newNode = (tree*)malloc(sizeof(tree));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)return newNode;
	if (data < root->data)
	{
		root->left = add(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = add(root->right,data);
	}
	return root;
}
void preOrder(tree* root)
{
	if (root == NULL)return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
int isBinarySearchTree(tree* root)
{
	if (root == NULL)return 1;
	if (isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data))
	{
		isBinarySearchTree(root->left);
		isBinarySearchTree(root->right);
		return 1;
	}
	else
		return 0;

}
int isSubtreeLesser(tree* root, int data)
{
	if (root == NULL)return 1;
	if (root->data < data && isSubtreeLesser(root->left, data) && isSubtreeLesser(root->right, data))
		return 1;
	else
		return 0;

}

int isSubtreeGreater(tree* root, int data)
{
	if (root == NULL)return 1;
	if (root->data >data && isSubtreeGreater(root->left,data) && isSubtreeGreater(root->right,data))
		return 1;
	else
		return 0;
}
int main()
{
	tree* root = NULL;
	root = add(root, 6);
	root = add(root, 4);
	root = add(root, 2);
	root = add(root, 5);
	root = add(root, 8);
	root = add(root, 10);
	preOrder(root);
	int result= isBinarySearchTree(root);
	if (result == 1)
	{
		printf("¼º°ø");
	}
	else
		printf("½ÇÆÐ");
	return 0;
}
