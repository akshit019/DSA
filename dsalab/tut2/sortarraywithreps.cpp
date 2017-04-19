#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	int count;
};

Node* getnewnode(int data){

	Node* n = new Node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->count = 1;
	return n;
}

Node* insertbst(Node* root, int key){

	if (root == NULL)
	{
		return getnewnode(key);
	}

	if (key == root->data)
	{
		root->count = root->count +1;
	}

	else if(key < root->data){
		root->left = insertbst(root->left, key);
	}

	else if (key > root->data){
		root->right = insertbst(root->right, key);
	}
	
	else
		return root;
}

void inorder(Node* root){

	if (root == NULL)
	{
		return;
	}

	inorder(root->left);

	for (int i = 0; i < root->count; ++i)
	{
		cout << root->data << " ";
	}
	
	inorder(root->right);
}


int main()
{
	int arr[9] = {1, 5, 4, 3, 9, 9, 5, 3, 1};
	//sort it

	Node* root = NULL;

	//root = insertbst(root, 5);
	for (int i = 0; i < 9; ++i)
	{
		root = insertbst(root, arr[i]);
	}

	inorder(root);

	return 0;
}