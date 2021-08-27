//
//  Created by Furkan Kerim YILDIRIM on 13.08.2021.
//  furkanyildirim 28138

#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(){
//  postcondition: construct empty 2D int Matrix
    
    rows = cols = 0;
    data = NULL;
}


Matrix::Matrix(int r, int c): rows(r), cols(c) {
//  postcondition: construct empty 2D int Matrix with size
    
    // Set rows of data
    data = new int * [rows];
    
    // Set cols of data
    for (int i = 0; i < rows; i++){
        data[i] = new int[cols];
    }
}


Matrix::Matrix(const Matrix & m): rows(m.rows), cols(m.cols) {
//  postcondition: construct 2D int Matrix with deep copy
    
    // Set rows of data
    data = new int * [rows];
    
    // Set cols of data
    for (int i = 0; i<rows; i++){
        data[i] = new int[cols];
        
        // Deep copy matrix from given matrix
        for (int j = 0; j < cols; j++) {
            data[i][j] = m.data[i][j];
        }
    }
}


Matrix::~Matrix(){
//  postcondition: destruct 2D int Matrix
    
    Delete();
}


int Matrix::GetIndex(int i, int j) const {
//  postcondition: return matrix cell value from given index

    return data[i][j];
}


int & Matrix::GetRef(int i, int j){
//  postcondition: return matrix cell ref. value from given index
    
    return data[i][j];
}


void Matrix::SetIndex(int i, int j, int value){
//  postcondition: set matrix cell value from given index
    
    data[i][j] = value;
}


void Matrix::Print() const {
//  postcondition: prints entire matrix
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout  << setw(5) << data[i][j];
        }
        cout << endl;
    }
}


void Matrix::Delete() {
//  postcondition: deletes all matrix
    
    // Deletes all cols
    for (int i = 0; i<rows; i++){
        delete [] data[i];
    }
    
    // Deletes all rows
    delete [] data;
}


bool Matrix::isValid(int i, int j) const {
// postcondition: make sure that cell index is valid
    
    if (i >= 0 && i < rows && j >= 0 && j < cols) return true;
    else return false;
}


bool Matrix::Equals(const Matrix & m) {
//  postcondition: make sure that matrixes are the same
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != m.data[i][j]) return false;
        }
    }
    return true;
}


const Matrix & Matrix::operator=(const Matrix & m) {
// postcondition: sync queue to given queue
    
    // make sure that self assignment
    if (this != &m) {
        
        // clear previous assignments
        Delete();
        
        // Set new matrix sizes
        rows = m.rows;
        cols = m.cols;
        
        // Set rows of data
        data = new int * [rows];
        
        // Set cols of data
        for (int i = 0; i<rows; i++){
            data[i] = new int[cols];
            
            // Deep copy matrix from given matrix
            for (int j = 0; j < cols; j++) {
                data[i][j] = m.data[i][j];
            }
        }
    }
    return *this;
}


bool Matrix::operator == (const Matrix & m) {
//  postcondition: make sure that matrixes are the same
    
    return Equals(m);
}
