/*Author: Gizem Gezici
  Date: 12.03.2012
  Doubly Linked List Source File Implementation
*/

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

linkedlist::linkedlist(){
	head=NULL;
	tail = NULL;
}

void linkedlist::printList(){
	cout << "Printing the linked list..." << endl;
	node * ptr = head;
	// List is empty
	if(head == NULL){
		cout << "List is empty" << endl;
	}
	else{
		while(ptr != NULL){
			cout << ptr->data << endl;
			ptr = ptr->right;
		}
	}
}

void linkedlist::addToEnd(string n){
	node *ptr = head;

	//List is empty
	if(tail == NULL){
		node *temp = new node(n, NULL, NULL);
		tail = temp;
		head = tail;
	}
	else{
		node *temp = new node(n, NULL, tail);
		tail->right = temp;
		tail = temp;
	}
}

void linkedlist::addToBeginning(string n){
	// List is empty
	if(head == NULL){
		node *ptr = new node(n, NULL, NULL);
		head = ptr;
		tail = head;	
	}
	else{
		node *ptr = new node(n, head, NULL);
		head->left = ptr;
		head = ptr;
	}
}


// Delete Function implemented here
void linkedlist::deleteAll(){
	cout << "Deleting the linked list..." << endl;
	
	if(head != NULL){
		node *ptr = head;
		node *ptr2 = head->next;
		
		while(ptr2 != NULL){
			delete ptr;
			ptr = ptr2;
			ptr2 = ptr2->next;
		}
		
		delete ptr;
	}
	
}

void linkedlist::printListInverse(){
	cout << "Printing the linked list in reverse order..." << endl;
	node *ptr = tail;
	// List is empty
	if(tail == NULL){
		cout << "List is empty" << endl;
	}
	else{
		while(ptr != NULL){
			cout << ptr->data << endl;
			ptr = ptr->left;
		}
	}
}

