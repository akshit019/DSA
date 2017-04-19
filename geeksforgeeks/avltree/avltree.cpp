#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	int height;
};

int getheight(node* n){

	if (n == NULL)
	{
		return 0;
	}

	return n->height;
}

node* getnewnode(int key){

	node* n = new node();
	n->data = key;
	n->left = NULL;
	n->right = NULL;
	n->height = 1;

	return n;
}

// rotate right with y as root
node* rotateright(node* y){

	node* x = y->left;
	node* t2 = x->right;

	//rotation
	x->right = y;
	y->left = t2;

	y->height = max(getheight(y->left), getheight(y->right))+1;
	x->height = max(getheight(x->left), getheight(x->right))+1;

	return x; //new root
}

node* rotateleft(node* x){

	node* y = x->right;
	node* t2 = y->left;

	//rotation
	y->left = x;
	x->right = t2;

	x->height = max(getheight(x->left), getheight(x->right))+1;
	y->height = max(getheight(y->left), getheight(y->right))+1;

	return y;
}

int getbalance(node* n){

	if (n == NULL)
	{
		return 0;
	}

	return (getheight(n->left) - getheight(n->right));
}

node* avlinsert(int key, node* root){

	if(root == NULL){
		return (getnewnode(key));
	}

	else if (key < root->data)
	{
		root->left = avlinsert(key, root->left);
	}

	else if (key > root->data)
	{
		root->right = avlinsert(key, root->right);
	}

	else 
		return root; //equal keys not allowed

	root->height = 1 + max(getheight(root->left), getheight(root->right));

	int balance = getbalance(root);

	//4 cases:

	//left-left case:
	if (balance > 1 && key < root->left->data)
	{
		return rotateright(root);
	}

	//right-right case:
	else if (balance < -1 && key > root->right->data)
	{
		return rotateleft(root);
	}

	//left-right case:
	else if (balance > 1 && key > root->left->data)
	{
		root->left = rotateleft(root->left);
		return rotateright(root);
	}

	//right-left case:
	else if (balance < -1 && key < root->right->data)
	{
		 root->right = rotateright(root->right);
		 return rotateleft(root);
	}

	return root;
}

node* findmin(node* root){
	
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

node* deletenode(node* root, int dkey){

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

	//if key is same as root, this is the node that needs to be deleted
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
			node* temp = root;
			root = root->right;
			delete temp;
		}

		else if (root->right == NULL)
		{
			node* temp = root;
			root = root->left;
			delete temp;
		}

		//case 3: two children | important
		else
		{
			node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = deletenode(root->right, temp->data);
		}

		return root;
	}

	root->height = 1 + max(getheight(root->left), getheight(root->right));

	int balance = getbalance(root);

	//4 cases:
	//left-left case:
	if (balance > 1 && getbalance(root->left) >= 0)
	{
		return rotateright(root);
	}

	//right-right case:
	else if (balance < -1 && getbalance(root->right) <= 0)
	{
		return rotateleft(root);
	}

	//left-right case:
	else if (balance > 1 && getbalance(root->left) < 0)
	{
		root->left = rotateleft(root->left);
		return rotateright(root);
	}

	//right-left case:
	else if (balance < -1 && getbalance(root->right) > 0)
	{
		 root->right = rotateright(root->right);
		 return rotateleft(root);
	}

	return root;
	
}

void preorder(node* root){

	if (root == NULL)
	{
		return;
	}

	cout << root->data << " ";

	preorder(root->left);

	preorder(root->right);
}

int main(int argc, char const *argv[])
{
	node* root = NULL; //empty avltree

	root = avlinsert(9, root);
	root = avlinsert(5, root);
	root = avlinsert(10, root);
	root = avlinsert(0, root);
	root = avlinsert(6, root);
	root = avlinsert(11, root);
	root = avlinsert(-1, root);
	root = avlinsert(1, root);
	root = avlinsert(2, root);

	preorder(root);

	root = deletenode(root, 10);
	cout << endl;

	preorder(root);
	return 0;
}