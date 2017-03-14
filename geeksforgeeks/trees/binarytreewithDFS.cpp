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

void preorder(Node* n){
	
	if (n == NULL)
	{
		return;
	}

	cout << n->data << " ";

	preorder(n->left);

	preorder(n->right);	
}

void inorder(Node* n){

	if (n == NULL)
	{
		return;
	}

	inorder(n->left);

	cout << n->data << " ";

	inorder(n->right);
}

void postorder(Node* n){

	if(n==NULL){
		return;
	}

	postorder(n->left);

	postorder(n->right);

	cout << n->data << " ";
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

	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	preorder(root);

	return 0;
}