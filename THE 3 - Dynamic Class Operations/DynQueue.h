//
//  Created by Furkan Kerim YILDIRIM on 12.08.2021.
//  furkanyildirim 28138

#ifndef _DYNQUEUE_H
#define _DYNQUEUE_H
using namespace std;


// Queue Struct

template <class Type>
struct QueueNode{                                   //  dynamic template queue struct
    Type info;                                      //  queue elementh data
    QueueNode *next;                                //  next elementh link
    
    QueueNode() {};                                 //  default constructor
    QueueNode(Type val, QueueNode *ptr = NULL){     //  valid constructor
        info = val;
        next = ptr;
    }
};


// Header Implementations

template <class Type>
class DynQueue {
    
public:
    
    // Constructors and destructors
    
    DynQueue(void)                                                  ;   //  construct empty dynamic template class
    DynQueue(const DynQueue<Type> &)                                ;   //  construct dynamic template class with deep copy
    ~DynQueue(void)                                                 ;   //  destruct dynamic template class
    
    
    // Member functions
    
    void enqueue(Type)                                              ;   //  add item to end of queue
    void dequeue(Type &)                                            ;   //  get and pop item from head of queue
    void clear(void)                                                ;   //  delete all items of dynamic queue
    bool isEmpty(void) const                                        ;   //  make sure that the dynamic queue is empty
    
    
    // Iterators
    
    QueueNode<Type> * getFront(void) const                          ;   //  get front pointer of dynamic queue
    QueueNode<Type> * getRear(void)  const                          ;   //  get rear pointer of dynamic queue
    
    
    // Member operator overloadings
    
    const DynQueue<Type> & operator =  (const DynQueue<Type> &)     ;   //  sync queue to given queue
    const DynQueue<Type> & operator += (const Type)                 ;   //  add item to end of queue
    const DynQueue<Type> & operator *= (const int)                  ;   //  multiply all items with given number
    
private:
    
    // Variables
    
    QueueNode<Type> * front                                         ;   //  the top node of dynamic queue
    QueueNode<Type> * rear                                          ;   //  the end node of dynamic queue
    int size                                                        ;   //  dynamic queue size
};


// Free operator overloadings

template <class Type>
DynQueue<Type> operator + (const DynQueue<Type> &, const DynQueue<Type> &)  ;   //  add the elements of the two dynamic queue

template <class Type>
ostream & operator << (ostream & os, const DynQueue<Type> & queue)          ;   //  display the items of dynamic queue

template <class Type>
ifstream & operator >> (ifstream &, DynQueue<Type> &)                       ;   // add items to dynamic queue from file




// Function Implementations

template <class Type>
DynQueue<Type>:: DynQueue(){
// postcondition: construct empty dynamic template class
    
    // Set default variables
    front = rear = NULL;
    size = 0;
}

template <class Type>
DynQueue<Type>::DynQueue(const DynQueue<Type> & copy){
// postcondition: construct dynamic template class with deep copy
    
    // Set default variables
    front = rear = NULL;
    size = 0;
    
    // Add items to queue
    QueueNode<Type> * temp = copy.getFront();
    while (temp != NULL) {
        enqueue(temp->info);
        temp = temp->next;
    }
}

template <class Type>
DynQueue<Type>::~DynQueue(){
// postcondition: destruct dynamic template class
    
    clear();
}

template <class Type>
void DynQueue<Type>::enqueue(Type value){
// postcondition: add item to end of queue
    
    // when queue is empty
    if (rear == NULL) {
        QueueNode<Type> * ptr = new QueueNode<Type>(value);
        front = rear = ptr;
        size++;
    }
    
    // when queue is not empty
    else {
        rear->next = new QueueNode<Type>(value);
        rear = rear->next;
        size++;
    }
    
}

template <class Type>
void DynQueue<Type>::dequeue(Type & value){
// postcondition: get and pop item from head of queue
    
    if (!isEmpty()) {
        QueueNode<Type> * temp = getFront();
        value = front->info;
        front = front->next;
        delete temp; size--;
    }
}

template <class Type>
void DynQueue<Type>::clear(){
// postcondition: make sure that the dynamic queue is empty
    
    // create temp value
    Type tempValue;

    // delete all items
    while (!isEmpty()) {
        dequeue(tempValue);
    }
    
    // set default variables
    front = rear = NULL;
    size = 0;
}

template <class Type>
bool DynQueue<Type>::isEmpty() const {
// postcondition: make sure that the dynamic queue is empty
    
    if (front == NULL) return true;
    else return false;
}

template <class Type>
QueueNode<Type> * DynQueue<Type>::getFront() const {
// postcondition: get front pointer of dynamic queue
    
    return front;
};

template <class Type>
QueueNode<Type> * DynQueue<Type>::getRear() const {
// postcondition: get front pointer of dynamic queue
    
    return rear;
};

template <class Type>
const DynQueue<Type> & DynQueue<Type>::operator = (const DynQueue<Type> & rhs) {
// postcondition: sync queue to given queue

    // make sure that self assignment
    if (this != &rhs) {
        
        // clear previous assignments
        clear(); size = 0;
        front = rear = NULL;
    
        // copy right hand side queue
        QueueNode<Type> * temp = rhs.front;
        while (temp != NULL) {
            enqueue(temp->info);
            temp = temp->next;
        }
    }
    
    return *this;
}

template <class Type>
const DynQueue<Type> & DynQueue<Type>::operator += (const Type obj) {
// postcondition: add item to end of queue
    
    enqueue(obj);
    return *this;
}

template <class Type>
const DynQueue<Type> & DynQueue<Type>::operator *= (const int num) {
// postcondition: multiply all items with given number
    
    // clone front queue node multiply all items
    QueueNode<Type> * ptr = getFront();
    
    while (ptr != NULL) {
        Type value = ptr->info;
        
        // multiplication process
        for (int i = 1; i < num; i++) {
            ptr->info += value;
        }
        
        ptr = ptr->next;
    }
    
    return *this;
}

template <class Type>
DynQueue<Type>  operator + (const DynQueue<Type> & lhs, const DynQueue<Type> & rhs) {
// postcondition: add the elements of the two dynamic queue

    // create empty queue
    DynQueue<Type> result;
    
    // get front nodes
    QueueNode<Type> * lPtr = lhs.getFront();
    QueueNode<Type> * rPtr = rhs.getFront();
    
    // addition process
    while (lPtr != NULL && rPtr != NULL) {
        result.enqueue(lPtr->info + rPtr->info);
        lPtr = lPtr->next;
        rPtr = rPtr->next;
    }

    return result;
}

template <class Type>
ostream & operator << (ostream & os, const DynQueue<Type> & queue) {
// postcondition: display the items of dynamic queue

    // create temp queue
    DynQueue<Type> temp(queue);
    Type obj;
    
    // prints data
    os.fill(0);
    while (!temp.isEmpty()) {
        temp.dequeue(obj);
        os << obj << " ";
    }
    
    return os;
}

template <class Type>
ifstream & operator >> (ifstream & is, DynQueue<Type> & queue){
// postcondition: add items to dynamic queue from file

    Type obj;
    while (is >> obj) {
        queue.enqueue(obj);
    }
    
    return is;
}

#endif /* _DYNQUEUE_H */
