//
//  Created by Furkan Kerim YILDIRIM on 4.08.2021.
//  furkanyildirim 28138

#include "LinkedList.h"

LinkedList::LinkedList(void) {
    head = NULL;
    size = 0;
}

LinkedList::LinkedList(const LinkedList & copy) {
    head = copy.createClone();
    size = copy.size;
}

LinkedList::~LinkedList(void) {
    node *ptr = head;
    
    while (ptr != NULL) {
        ptr = ptr->next;
        delete head;
        head = ptr;
    }
}

void LinkedList::addToBeginning(const int num) {
    if(head == NULL){
        head = new node(num, NULL);

    } else{
        node * ptr = new node(num, head);
        head = ptr;
    }
}

void LinkedList::addToEnd(const int num) {
    node * ptr = head;
    
    if (head == NULL) {
        head = new node(num);
        
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        
        ptr->next = new node(num);
    }
}

node * LinkedList::createClone(void) const {
    if (head == NULL) {
        return NULL;
    }
    
    node * headClone = new node(head->value);
    node * ptr = head->next;
    node * ptrClone = headClone;
    
    while (ptr != NULL) {
        
        ptrClone->next = new node(ptr->value);
        ptrClone = ptrClone->next;
        ptr = ptr->next;
    }
    
    return headClone;
}

void LinkedList::printList(){
    node * ptr = head;
    // List is empty
    if(head == NULL){
        cout << "List is empty" << endl;
    }
    else{
        while(ptr != NULL){
            cout << ptr->value << endl;
            ptr = ptr->next;
        }
    }
}

void LinkedList::printListInverse(){
    if(head != NULL){
        printListInverse(head);
    }
}

void LinkedList::printListInverse(node *n){
    if(n->next != NULL){
        printListInverse(n->next);
    }
    cout << n->value << endl;
}

void LinkedList::deleteItem(const int num) {
    node * ptr = head;
    node * prev = NULL;
    
    if (ptr != NULL && ptr->value == num) {
         head = ptr->next;
         delete ptr;
         return;
     
    } else {
        while (ptr != NULL && ptr->value != num) {
            prev = ptr;
            ptr = ptr->next;
        }
  
     if (ptr == NULL) return;
  
     prev->next = ptr->next;
     delete ptr;
    }
}

void LinkedList::deleteList (void){
    node * ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
        delete head;
        head = ptr;
    }
    size = 0;
}
