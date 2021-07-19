//
//  Created by Furkan Kerim YILDIRIM on 14.07.2021.
//

//  Consider the following function definition, which aims to find
//  and return the summation of the numbers on the diagonal of a matrix.
//  If the matrix is not a square matrix, the result should be zero.

//  Please fill in the blanks so that the function is complete.
//  You may assume that (i) vector has enough number of rows/columns with initialized elements,
//  and (ii) rows of the matrix have equal number of elements.

#include <iostream>
#include <vector>
using namespace std;

int findSummationDiagonal (vector<vector<int> > & matrix){
  int sum = 0;
  if (matrix.size() == matrix[0].size()) {
      for (int i = 0; i <matrix.size(); i++) {
        sum += matrix[i][i];
     }
  }
    return sum;;
}

int main() {
    
    // For trying...
    vector<int> row = {1,2,5,4,3};
    vector<vector<int>> matrix (5,row);
    cout << findSummationDiagonal(matrix);
    return 0;
}
