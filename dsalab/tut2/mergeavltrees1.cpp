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

int i=0;
int arr[10];

void preorder(node* root){

	if (root == NULL)
	{
		return; 
	}

	arr[i] = root->data;
	i++;

	preorder(root->left);

	preorder(root->right);
}

void inorder(node* root){

	if (root == NULL)
	{
		return;
	}

	inorder(root->left);

	cout << root->data << " ";

	inorder(root->right);
}

int main()
{
	node* root1 = NULL;

	root1 = avlinsert(100, root1);
	root1 = avlinsert(50, root1);
	root1 = avlinsert(300, root1);
	root1 = avlinsert(20, root1);
	root1 = avlinsert(70, root1);

	node* root2 = NULL;

	root2 = avlinsert(80, root2);
	root2 = avlinsert(40, root2);
	root2 = avlinsert(120, root2);


	preorder(root2);

	for (int i = 0; i < 3; ++i)
	{
		cout << arr[i] << " ";
	}

	for (int i = 0; i < 3; ++i)
	{
		root1 = avlinsert(arr[i], root1);
	}

	inorder(root1);

	return 0;
}