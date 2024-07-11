//To find maximum path sum in non-empty Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return (newNode);
}

int findMaximumPath(Node* root, int& res)
{
	if (root == NULL)
		return 0;

	int l = findMaximumPath(root->left, res);
	int r = findMaximumPath(root->right, res);

	int max_one = max(max(l, r) + root->data, root->data);
	int max_up = max(max_one, l + r + root->data);

	res = max(res, max_up);

	return max_one;
}

int findMaximumSum(Node* root)
{
	int res = INT_MIN;
	findMaximumPath(root, res);
	return res;
}

int main(void)
{
	struct Node* root = newNode(4);
	root->left = newNode(6);
	root->right = newNode(1);
	root->left->left = newNode(2);
	root->left->right = newNode(11);
	root->right->right = newNode(5);
	root->right->right->left = newNode(21);
	root->right->right->right = newNode(14);
    
	cout << "Max path sum is " << findMaximumSum(root);
	return 0;
}
