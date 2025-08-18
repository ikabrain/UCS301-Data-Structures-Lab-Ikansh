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

struct node* recurSearchTree(struct node *n, int val)
{
	if (n == NULL || n->data == val)
		return n;
	
	if (val < n->data)
		return recurSearchTree(n->left, val);
	else
		return recurSearchTree(n->right, val);
}

struct node* iterSearchTree(struct node *root, int val)
{
	struct node *n = root;
	while (n != NULL && n->data != val)
	{
		if (val < n->data)
			n = n->left;
		else
			n = n->right;
	}
	return n;
}

struct node* maxNode(struct node *root)
{
	struct node *temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

struct node* minNode(struct node *root)
{
	struct node *temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

struct node* treeSuccessor(struct node* root, int val)
{
	// If node->right has some value, then node's successor is the minimum of the tree to it's right!
	// If node->right is null & node is left child, then parent is successor
	//		 			But if node is right child, then goto nearest ancestor for which node is in a left subtree!!!
	struct node* current = recurSearchTree(root, val);
	if (current == NULL) return NULL;
	if (current->right != NULL)
		return minNode(current->right);
	else
	{
		struct node* ancestor = root;	// = Keeps track of how we are reaching current node from root! 
		struct node* successor = NULL;	// = Deepest ancestor which has current node in it's left subtree
		while (ancestor != current)
		{
			if (val < ancestor->data) // Current to left of ancestor
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
	 
}

struct node* treePredecessor(struct node *root, int val)
{
	struct node *current = recurSearchTree(root, val);
	if (current == NULL)
		return NULL;
	if (current->left != NULL)
		// n = current->left, while n->right!=null, n=n->right !!!
		return maxNode(current->left);
	else
	{
		// Here, find deepest ancestor for which current is in it's right sub-tree!
		struct node *ancestor = root;
		struct node *successor = NULL;
		while (ancestor != current)
		{
			if (val < ancestor->data)
			{
				ancestor = ancestor->left;
			}
			else
			{
				successor = ancestor;
				ancestor = ancestor->right;
			}
		}
	}
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
	
	int x;
	printf("Enter value to search in tree: ");
	scanf("%d", &x);
	struct node *recur = recurSearchTree(root, x);
	struct node *iter = iterSearchTree(root, x);
	if (recur == NULL || iter == NULL)
		printf("\nNode not found.\n");
	else
		printf("\nNode found using recursion and iteration!\n");
		
	struct node *max = maxNode(root);
	struct node *min = minNode(root);
	printf("\nMax value in tree = %d\n", max->data);
	printf("Min value in tree = %d\n", min->data);
	
	struct node *succ = treeSuccessor(root, x);
	if (succ != NULL)
	{
		printf("\n  In-order Successor of %d = %d\n", x, succ->data);
	}
	struct node *pred = treePredecessor(root, x);
	printf("In-order Predecessor of %d = %d\n", x, pred->data);
	
	return 0;
}
