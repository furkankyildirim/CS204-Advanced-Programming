/*Author: Gizem Gezici
  Date: 12.03.2012
  Doubly Linked List Header File Implementation
*/

#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H
#include <string>
using namespace std;

struct node{
	string data;
	node *right;	// forward direction
	node *left;		// backward direction

	node(){}

	node(const string &s, node * linkRight, node * linkLeft){
		data = s;
		right = linkRight;
		left = linkLeft;
	}
};

class linkedlist{
private:
	node *head;		// Head node, start of LinkedList
	node *tail;		// Tail node, end of LinkedList

public:
	linkedlist();			// Constructor
	void printList();		// Prints the given LinkedList from head to end
	// Not Recursive!
	void printListInverse(); // Prints the given LinkedList from end to head (by using tail node)

	void addToBeginning(string n);	// Inserts new node at the beginning of the LinkedList with given data
	void addToEnd(string n);	// Inserts new node at the end of the LinkedList with given data
	
	void deleteAll();
};


#endif
