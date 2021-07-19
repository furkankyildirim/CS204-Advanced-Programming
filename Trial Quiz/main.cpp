//
//  Created by Furkan Kerim YILDIRIM on 7.07.2021.
//  furkanyildirim 28138

//  Write a C++ function that takes two integer values
//  (say n1 and n2) as its only parameters and returns their sum.

//  For example:
//  Test                    Result
//  cout << func(3, 5);     8
//  cout << func(-3, 5);    2


#include <iostream>
using namespace std;

int func(const int n1, const int n2) {
    int sum;
    
    sum = n1 + n2;
    return sum;
}

int main() {
    
    cout << func(3, 5) << endl;
    cout << func(-3, 5) << endl;
    return 0;
}
