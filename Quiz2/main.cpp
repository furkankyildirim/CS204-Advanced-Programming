//
//  Created by Furkan Kerim YILDIRIM on 04.08.2021.
//  furkanyildirim 28138

//  Implement a function with the following prototype:
//  double findAverageItemLength(DynamicStringQueue & queue)

//  This function takes a dynamic string queue object and returns the average string lenght.
//  Be reminded that divison by zero results in a crash; your function implementation must
//  handle such a case by returning 0. Besides, at the end of the function, the parameter
//  queue must be in its initial form (i.e , same elements with the same order).

//  Bellow you can find the declaration of the DynamicStringQueue class that you are allowed to
//  use in this question. Please note that you cannot modify this given DynamicStringQueue class.

//  struct QueueNode {
//      string value;
//      QueueNode * next;
//  };
//
//  class DynamicStringQueue {
//  private:
//      QueueNode * front, * rear;
//
//  public:
//      DynamicStringQueue(void);
//      ~DynamicStringQueue(void);
//      void enqueue(string);
//      void dequeue(string &);
//      bool isEmpty(void);
//  };

//  Please note that you cannot use the help of another container data structer (i.e. static/dynmaic
//  array, linked list, stack, etc.) However you may consider using help from another dynamic string
//  queue object.

//  For instance, if the parameter queue has the following sequence of items then the function should
//  return 6.6.

//  "duygu", "karaoglan", "altop", "204", "summer term"

#include <iostream>
#include <string>
using namespace std;

double findAverageItemLength(DynamicStringQueue & queue) {
    string temp;
    double letterCount = 0, wordCount = 0, average;
    DynamicStringQueue tempQueue;
    
    if (queue.isEmpty()) {
        return 0;
        
    } else {
        while (!queue.isEmpty()) {
            queue.dequeue(temp);
            tempQueue.enqueue(temp);
            
            for (char _ : temp) {
                letterCount++;
            }
            wordCount++;
        }
        
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(temp);
            queue.enqueue(temp);
        }
        
        average = letterCount / wordCount;
        return average;
    }
}


int main(){
    
    // For trying...
    DynamicStringQueue queue;
    
    queue.enqueue("duygu");
    queue.enqueue("karaoglan");
    queue.enqueue("altop");
    queue.enqueue("204");
    queue.enqueue("summer term");
    
    cout << findAverageItemLength(queue)<< endl;
    
    return 0;
}
