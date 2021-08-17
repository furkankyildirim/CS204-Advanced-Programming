//
//  Created by Furkan Kerim YILDIRIM on 4.08.2021.
//  furkanyildirim 28138

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>

using namespace std;

struct node {
    int value;
    node * next;
    
    node(){
        value = 0;
        next = NULL;
    };
    
    node (int num = 0, node * ptr = NULL) : value(num), next(ptr)  {};
};

class LinkedList {
public:
    
    LinkedList (void);
    LinkedList (const LinkedList &);
    ~LinkedList(void);
    
    void addToEnd(const int);
    void addToBeginning(const int);
    void deleteItem (const int);
    void deleteList (void);
    
    void printList();
    void printListInverse();
    

    
    node * createClone (void) const;
    
private:
    node * head;
    int size;
    void printListInverse(node *);
    
};

#endif /* _LINKEDLIST_H */
