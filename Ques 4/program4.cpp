//Serialize and Deserialize methods of Binary Tree

#include <bits/stdc++.h>
using namespace std;
#define DISNODE -1

struct Node {
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int key)
{
	struct Node* temp = new Node();
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

void serialize(Node* root, FILE* fp)
{
	if (root == NULL) {
		fprintf(fp, "%d ", DISNODE);
		return;
	}
	fprintf(fp, "%d ", root->key);
	serialize(root->left, fp);
	serialize(root->right, fp);
}

void deSerialize(Node*& root, FILE* fp)
{
	int val;
	if (!fscanf(fp, "%d ", &val) || val == DISNODE)
		return;
    
	root = newNode(val);
	deSerialize(root->left, fp);
	deSerialize(root->right, fp);
}

void inorder(Node* root)
{
	if (root) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(4);
	root->right = newNode(11);
	root->left->left = newNode(3);
	root->left->right = newNode(6);
	root->left->right->left = newNode(5);
	root->left->right->right = newNode(7);

	FILE* fp = fopen("tree.txt", "w");
	if (fp == NULL) {
		puts("Could not open file");
		return 0;
	}
	serialize(root, fp);
	fclose(fp);

	Node* root1 = NULL;
	fp = fopen("tree.txt", "r");
	deSerialize(root1, fp);

	printf("Inorder Traversal of the tree constructed from file:\n");
	inorder(root1);

	return 0;
}
