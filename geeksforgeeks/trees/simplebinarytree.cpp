#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int main()
{
	Node* root = NULL; //empty tree

	Node* n = new Node();
	n->data = 1;
	n->left = NULL;
	n->right = NULL;

	root = n;

	Node* n1 = new Node();
	n1->data = 2;
	n1->left = NULL;
	n1->right = NULL;

	root->left = n1;

	Node* n2 = new Node();
	n2->data = 3;
	n2->left = NULL;
	n2->right = NULL;

	root->right = n2;

	cout << root->data;
	cout << root->left->data;
	cout << root->right->data;

	return 0;
}