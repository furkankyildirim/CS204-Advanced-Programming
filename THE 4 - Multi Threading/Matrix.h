//
//  Created by Furkan Kerim YILDIRIM on 13.08.2021.
//  furkanyildirim 28138

#ifndef _MATRIX_H
#define _MATRIX_H


class Matrix {
    
    // Iterators
    
    friend class MatrixItr                                  ;   //  for iterating matrix
    
    
public:
    
    // Constructors and destructors

    Matrix()                                                ;   //  construct empty 2D int Matrix
    Matrix(int, int)                                        ;   //  construct empty 2D int Matrix with size
    Matrix(const Matrix &)                                  ;   //  construct 2D  int Matrix with deep copy
    ~Matrix()                                               ;   //  destruct 2D int Matrix
    
    
    // Member functions
    
    int GetIndex (int, int)                            const;   //  return matrix cell value from given index
    int& GetRef  (int, int)                                 ;   //  return matrix cell ref. value from given index
    void SetIndex (int, int, int)                           ;   //  set matrix cell value from given index
    void Print (void)                                  const;   //  prints entire matrix
    void Delete (void)                                      ;   //  deletes all matrix
    bool isValid(int, int)                             const;   //  make sure that the cell index is valid
    bool Equals (const Matrix &)                            ;   //  make sure that matrixes are the same

    
    // Member operator overloadings
    
    const Matrix & operator = (const Matrix &)              ;   //  sync 2 matrixes
    bool operator == (const Matrix &);                      ;   //  make sure that matrixes are the same
    
private:
    
    // Variables

    int rows, cols                                          ;   //  the row and column size of 2D matrix
    int ** data                                             ;   //  includes 2D dynamic matrix data
};


class MatrixItr {                       //  Matrix iterator -> used to get the sizes of the matrix -> rows, cols
public:
    MatrixItr(const Matrix & m) : rows(m.rows), cols(m.cols) {}
    int rows, cols;
};

#endif /* Matrix_h */
