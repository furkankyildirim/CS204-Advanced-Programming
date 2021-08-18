//
//  Created by Furkan Kerim YILDIRIM on 18.08.2021.
//  furkanyildirim 28138

//  Write a function that takes an integer parameter, say searchNum, and a LinkedList parameter,
//  say theList. The linked list theList already sorted in ascending manner. This function
//  should return the largest element stored in theList, which is less than or equal to
//  searchNum. If the smallest element of theList is larger searchNum or theList is empty
//  then the function should return INT_MIN. Implementation must utilize LinkedListIterator.

//  However, the function is incomplete. Complete this function by filling in the boxes. More
//  specifically, give the initial value of num in the first box; write the required member
//  function calls on iter object in the second and fifth boxes; write an appropriate Boolean
//  expression in the third box; and assign the proper value to num in the fourth box.

//  You are not allowed to delete or update anything. Moreover, you cannot add anything than the
//  code that you are going to write in the boxes.

//  For your convenience the member function of the LinkedListIterator class are given as follows:
//  Init, Next, HasMore, Current.

#include <iostream>
#include "LinkedList.h"
using namespace std;

int SearchElement (const LinkedList & theList, int searchNum) {
    
    LinkedListIterator iter(theList);
    int num = INT_MIN;
    iter.Init();
    
    while (iter.HasMore() && iter.Current() <= searchNum) {
        num = iter.Current();
        iter.Next();
    }
    
    return num;
}

int main(){
    
    // For trying...
    LinkedList theList;
    int num = SearchElement(theList, 5);
    cout << num << endl;
    
    return 0;
}
