#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

void addatend(int data, Node* head){

	Node* temp = head;

	while(temp->next != NULL){
		temp = temp->next;
	}

	Node* n = new Node();
	n->data = data;
	n->next = NULL;
	n->prev = temp;
	temp->next = n;
}

void printll(Node* head){

	Node* temp = head;
	//cout << temp->prev << " ";
	cout << temp->data << " ";
	//cout << temp->next << endl;

	while(temp->next != NULL){
		temp = temp->next;
		//cout << temp->prev << " ";
		cout << temp->data << " ";
		//cout << temp->next << endl;
	}
}

Node* addatfront(int data, Node* head){

	Node* temp = head;

	Node* n = new Node();
	n->data = data;
	n->next = temp;
	n->prev = NULL;
	temp->prev = n;
	return n;
}

void reverseprintll(Node* head){

	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	while(temp->prev != NULL){
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << temp->data << " ";
}

int main()
{
	Node* head = NULL; //empty list

	Node* n = new Node();
	n->data = 1;
	n->next = NULL;
	n->prev = NULL;
	head = n;

	addatend(2, head);
	addatend(3, head);
	addatend(4, head);
	addatend(5, head);

	head = addatfront(0, head);
	printll(head);
	reverseprintll(head);

	return 0;
}