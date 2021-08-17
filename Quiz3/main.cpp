//
//  Created by Furkan Kerim YILDIRIM on 17.08.2021.
//  furkanyildirim 28138

//  Write a templated function (say getValue) that takes a vector of items
//  an index value, as its  only parameters. This function should return the
//  item at given index. If the given index is not a valid index for the given
//  vector, then your function should return the first item.

//  For exapmle:

//  vector<int> m;
//  for(int i = 1; i < 6; i++){
//      m.push_back(i);
//  }
//  cout << getValue(m,-1);

//  vector<int> m;
//  for(int i = 1; i < 6; i++){
//      m.push_back(i);
//  }
//  cout << getValue(m,1);

//  vector<double> m;
//  for(double i = 1.0; i < 6.0; i+=0.5){
//      m.push_back(i);
//  }
//  cout << getValue(m,5);

//  vector<string> m;
//  m.push_back("IF100");
//  m.push_back("CS201");
//  m.push_back("CS201");
//  m.push_back("CS300");
//  m.push_back("CS301");
//  cout << getValue(m,2);


#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class Type>
Type getValue(vector<Type> & data, int index) {
    if (index < data.size() && index > -1) {
        return data[index];
    } else {
        return data[0];
    }
}

int main(){
    
    // For trying...
    vector<string> m;
    m.push_back("IF100");
    m.push_back("CS201");
    m.push_back("CS204");
    m.push_back("CS300");
    m.push_back("CS301");
    cout << getValue(m,2);
    
    return 0;
}
