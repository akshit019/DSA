#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* getnewnode(int data){

	Node* n = new Node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

Node* bstsearch(Node* root, int key){

	if (root == NULL)
	{
		return root;
	}

	if(root->data == key)
	{
		return root;
	}

	else if (key > root->data)
	{
		bstsearch(root->right, key);
	}

	else
	{
		bstsearch(root->left, key);
	}

}

Node* bstinsert(Node* root, int key){

	if (root == NULL)
	{
		Node* n = getnewnode(key);
		return n;
	}

	if (key > root->data)
	{
		//cout << ".";
		root->right = bstinsert(root->right, key);
	}

	else if (key < root->data)
	{
		root->left = bstinsert(root->left, key);
	}

	return root;
	//assuming no repitition of keys
}

stack<int> s;

void inorder(Node* root){

	if (root == NULL)
	{
		return;
	}

	inorder(root->left);

	s.push(root->data);

	inorder(root->right);
}



int main()
{
	Node* root = NULL; //empty BST
	
	root = bstinsert(root,8);
	root = bstinsert(root, 3);
	root = bstinsert(root, 10);
	root = bstinsert(root, 1);
	root = bstinsert(root, 6);
	root = bstinsert(root, 14);
	root = bstinsert(root, 4);
	root = bstinsert(root, 7);
	root = bstinsert(root, 13);

	inorder(root);

	int kmin = 4;
	int kth = s.size()-kmin;
	for(int i=0; i<kth; i++){
		s.pop();
	}

	int km = s.top();
	cout << km;

	return 0;
}