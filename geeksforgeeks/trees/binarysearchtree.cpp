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

	//assuming no repitition of keys
}

void inorder(Node* root){

	if (root == NULL)
	{
		return;
	}

	inorder(root->left);

	cout << root->data << " ";

	inorder(root->right);
}

//depth = height of tree - height of node-1
//height

int height(Node* root){

	if (root == NULL)
	{
		return 0;
	}

	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);

		if (lheight > rheight)
		{
			return 1+lheight;
		}
		else
		{
			return 1+rheight;
		}
	}
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

void printlevelorder(Node* root, int height){

	for (int i = 1; i <= height; ++i)
	{
		printgivenlevel(root, i);
	}
}

Node* findmin(Node* root){
	
	if (root == NULL)
	{
		return root;
	}
	
	if (root->left == NULL)
	{
		return root;
	}

	findmin(root->left);
}

Node* deletenode(Node* root, int dkey){

	if (root == NULL)
	{
		return root;
	}

	if (dkey > root->data)
	{
		root->right = deletenode(root->right, dkey);
	}

	else if (dkey < root->data)
	{
		root->left = deletenode(root->left, dkey);
	}

	else
	{
		//case 1: no child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;

		}

		//case 2: one child
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}

		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}

		else
		{
			Node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = deletenode(root->right, temp->data);
		}

		return root;
	}
	
}

int main()
{
	Node* root = NULL; //empty BST
	
	root = bstinsert(root,8);
	bstinsert(root, 3);
	bstinsert(root, 10);
	bstinsert(root, 1);
	bstinsert(root, 6);
	bstinsert(root, 14);
	bstinsert(root, 4);
	bstinsert(root, 7);
	bstinsert(root, 13);

	//cout << root->data;
	//cout << root->left->data;
	//cout << root->right->data;

	inorder(root);
	cout << endl;

	// Node* temp = bstsearch(root, 5);
	// if (temp == NULL)
	// {
	// 	cout << "-1" << " ";
	// }
	// else
	// 	cout << temp->data << endl;

	int h = height(root);
	printlevelorder(root,h);
	cout << endl;

	deletenode(root, 6);
	printlevelorder(root,h);


	return 0;
}