#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data){

	Node* n = new Node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
}

void printgivenlevel(Node* root, int level){

	if (root == NULL)
	{
		return;
	}
	if (level == 1)
	{
		cout << root->data << " ";
	}
	else if (level > 1)
	{
		printgivenlevel(root->left, level-1);
		printgivenlevel(root->right, level-1);
	}
}

void printlevelorder(Node* root){

	for (int i = 1; i <= 3; ++i)
	{
		printgivenlevel(root,i);
	}
}

int main()
{
	Node* root = getNewNode(1);

	root->left = getNewNode(2);
	root->right = getNewNode(3);

	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);

	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);

	printlevelorder(root);

	return 0;
}