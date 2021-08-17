//
//  Created by Furkan Kerim YILDIRIM on 4.08.2021.
//  furkanyildirim 28138

#include <iostream>
#include "DynamicStringQueue.h"

DynamicStringQueue::DynamicStringQueue(void) {
    front = NULL;
    rear = NULL;
}

DynamicStringQueue::DynamicStringQueue(const DynamicStringQueue & temp) {
//    front = temp.front;
//    rear = temp.rear;
    
    if (temp.front == NULL) {
        front = NULL;
        rear = NULL;
    } else {
        front = new node(temp.front->value);
        rear = front;
        
        node * ptr = temp.front->next;
        
        while (ptr != NULL) {
            rear->next = new node(ptr->value);
            rear = rear->next;
            ptr = ptr->next;
        }
    }
}

DynamicStringQueue::~DynamicStringQueue(void) {
    string value;
    while (!isEmpty()) {
        dequeue(value);
    }
}

bool DynamicStringQueue::isEmpty(void) const{
   if (front == NULL)
      return true;
   else
      return false;
}

void DynamicStringQueue::enqueue(string value){
    if (isEmpty()) {
        front = new node(value);
        rear = front;
        
    } else {
        rear->next = new node(value);
        rear = rear->next;
    }
    
}

void DynamicStringQueue::dequeue(string & value){
    node *temp;
    if (isEmpty()){
        return;
        
    } else{
       value = front->value;
       temp = front;
       front = front->next;
       delete temp;
    }
}
 

