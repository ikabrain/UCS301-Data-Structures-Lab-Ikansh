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

struct node* insertNode(struct node *n, int val)
{
	if (n == NULL)
		return createNode(val);
		
	if (val < n->data)
		n->left = insertNode(n->left, val);
	else if (n->data < val)
		n->right = insertNode(n->right, val);
		
	return n;
}

struct node* deleteNode(struct node *root, int val)
{
	// If no children, just remove reference from parent and free memory 
	// If one child, link parent to child node and proceed to free memory of current node
	// If two children, find the inorder successor (min in right subtree), copy it's value, and now delete recursively!!!
	if (root == NULL) return;
	
	// For searching AND linking both!
	if (val < root->data)
		root->left = deleteNode(root->left, val);
	else if (root->data < val)
		root->right = deleteNode(root->right, val);
	else
	{
		// When I find the correct root node
		// Case-1: No children
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			return root;
		}
		// Case-2: One child
		else if (root->left == NULL)
		{
			// we need to return the new node that'll replace link with current one to parent!
			struct node *temp = root;
			root = root->right;
			free(temp);
			return root;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root;
			root = root->left;
			free(temp);
			return root;
		}
		// Case-3: Two children
		else
		{
			// Finiding in-order successor
			struct node *temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			// Copying value of temp to root
			root->data = temp->data;
			// Deleting the in-order successor from the right subtree
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

void inorder(struct node *root)
{
	if (root == NULL) return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int main(void)
{
	int root_val, i, n;
	printf("Enter value of root of the tree: ");
	scanf("%d", &root_val);
	struct node *root = createNode(root_val);
	printf("Enter number of nodes you wish to insert: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int x;
		printf("Enter value of node %d: ", i);
		scanf("%d", &x);
		root = insertNode(root, x);
	}
	
	printf("In-order BST after insertion: ");
	inorder(root);
	printf("\n");
	
	
	return 0;
}
