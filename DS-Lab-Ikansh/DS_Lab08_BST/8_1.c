#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* createNode(int val)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insertNode(struct node* n, int val)
{
	if (n == NULL)
		return createNode(val);
	
	if (val < n->data)
		n->left = insertNode(n->left, val);
	else if (n->data < val)
		n->right = insertNode(n->right, val);
	// DO NOTHING if val == current node's data!	
	return n;
}


void preorder(struct node *n)
{
	if (n==NULL) return;
	printf("%d ", n->data);
	preorder(n->left);
	preorder(n->right);
}
void inorder(struct node *n)
{
	if (n==NULL) return;
	inorder(n->left);
	printf("%d ", n->data);
	inorder(n->right);
}
void postorder(struct node *n)
{
	if (n==NULL) return;
	inorder(n->left);
	inorder(n->right);
	printf("%d ", n->data);
}


int main(void)
{
	struct node *root = createNode(50);
	root = insertNode(root, 10);
	root = insertNode(root, 5);
	root = insertNode(root, 7);
	root = insertNode(root, 20);
	root = insertNode(root, 70);
	root = insertNode(root, 60);
	root = insertNode(root, 100);
	
	printf("\n PRE-ORDER: ");
	preorder(root);
	printf("\n  IN-ORDER: ");
	inorder(root);
	printf("\nPOST-ORDER: ");
	postorder(root);
	printf("\n");
	
	return 0;
}
