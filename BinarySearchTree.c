#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct Node{
	int key;
	Node *left;
	Node *right;
}Node;

Node *addNode(Node *root, int key)
{
	if (root == NULL) {
		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->key = key;
		new_node->left = NULL;
		new_node->right = NULL;
		root = new_node;
		return root;
	}
	else if (root->key > key)
		root->left = addNode(root->left, key);
	else
		root->right = addNode(root->right, key);
	
	return root;
}

Node *findMaxNode(Node *root)
{
	Node *temp = root;

	if (temp->right != NULL)
		temp->right = findMaxNode(temp->right);
	return temp;

}

Node *deleteNode(Node *root, int key)
{
	Node *temp = NULL;

	if (root->key > key)
		root ->left = deleteNode(root->left, key);
	else if (root->key < key)
		root ->right = deleteNode(root->right, key);
	else {
		if ((root->left != NULL) && (root->right != NULL)) {
			temp = findMaxNode(root->left);
			root->key = temp->key;
			printf("%p\n", root->left);
			root->left = deleteNode(root->left, temp->key);
			printf("%p\n", temp);
		}
		else {
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			
			free(temp);
		}
	}

	return root;
}

Node *searchNode(Node *root, int key)
{
	Node *temp = root;

	if (temp == NULL)
		return NULL;

	if (temp->key > key)
		searchNode(temp->left, key);
	else if (temp->key < key)
        searchNode(temp->right, key);
	else
		return temp;

}

void printTree(Node *root)
{
	Node *temp = root;

	if (temp != NULL) {
		printTree(temp->left);
		printf("%d\n", temp->key);
		printTree(temp->right);
	}
}

int main(void)
{
	Node *tree = NULL;

	tree = addNode(tree, 5);
	tree = addNode(tree, 1);
	tree = addNode(tree, 6);
	tree = addNode(tree, 17);
	tree = addNode(tree, 14);
	tree = addNode(tree, 21);

	//tree = deleteNode(tree, 1);
	//tree = deleteNode(tree, 14);
	tree = deleteNode(tree, 17);
	
	printTree(tree);

	getchar();
	return 0;
}
