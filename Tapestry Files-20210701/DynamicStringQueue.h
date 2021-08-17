//
//  Created by Furkan Kerim YILDIRIM on 4.08.2021.
//  furkanyildirim 28138

#ifndef DynamicStringQueue_h
#define DynamicStringQueue_h

#include <string>
using namespace std;

struct node{
    string value;
    node *next;
    node(){};
    node(string str, node *ptr = NULL){
        value = str;
        next = ptr;
    }
};

class DynamicStringQueue {
public:
    DynamicStringQueue(void);
    DynamicStringQueue(const DynamicStringQueue &);
    ~DynamicStringQueue(void);
    
    void enqueue(string);
    void dequeue(string &);
    bool isEmpty(void) const;
    

private:
    node * front;
    node * rear;
    
};


#endif /* DynamicStringQueue_h */
