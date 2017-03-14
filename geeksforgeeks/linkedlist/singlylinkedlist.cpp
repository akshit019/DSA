#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void addatend(int data, Node* head){

	Node* temp = head;

	while(temp->next != NULL){
		temp = temp->next;
	}

	Node* n = new Node();
	n->data = data;
	n->next = NULL;
	temp->next = n; 
}

void printll(Node* head){

	Node* temp = head;
	cout << temp->data << " ";
	while(temp->next != NULL){
		temp = temp->next;
		cout << temp->data << " ";
	}
}

Node* addatfront(int data, Node* head){

	Node* temp = head;

	Node* n = new Node();
	n->data = data;
	n->next = temp;
	
	return n;
}

void deleteatend(Node* head){

	Node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp->next = NULL;

}

Node* deleteatfront(Node* head){

	Node* temp = head;
	head = temp->next;
	return head;
}

int main()
{
	Node* head; 
	head = NULL; //empty list

	Node* n = new Node();
	n->data = 1;
	n->next = NULL;
	head = n;

	addatend(2, head);
	addatend(3, head);
	addatend(4, head);
	addatend(5, head);

	//addatfront returns address of the new head, which we store in head to update it
	head = addatfront(0, head);

	deleteatend(head);

	head = deleteatfront(head);
	
	printll(head);


	return 0;
}