//
//  Created by Furkan Kerim YILDIRIM on 13.08.2021.
//  furkanyildirim 28138

#ifndef _MUTEX_MATRIX_H
#define _MUTEX_MATRIX_H

#include <mutex>
using namespace std;

class MutexMatrix{
public:
    
    // Constructors and destructors
    
    MutexMatrix(void)               ;   //  construct empty 2D mutex Matrix
    MutexMatrix(int, int)           ;   //  construct empty 2D mutex Matrix with size
    ~MutexMatrix(void)              ;   //  destruct 2D mutex Matrix
    
    
    // Member functions
    
    void Delete(void)               ;   //  deletes all matrix
    void LockCell(int, int)         ;   //  locks cell's mutex which given index
    void UnlockCell(int, int)       ;   //  unlocks cell's mutex which given index
    bool TrylockCell(int, int)      ;   //  try locks cell's mutex which given index
    
private:
    
    // Variables
    
    mutex **mutexes                 ;   //  includes 2D dynamic mutex matrix data
    int rows, cols                  ;   //  the row and column size of 2D matrix
};


// Function Implementations

MutexMatrix::MutexMatrix(void) {
//  postcondition: construct empty 2D mutex Matrix
    
    rows = cols= 0;
    mutexes = NULL;
}


MutexMatrix::MutexMatrix(int r, int c): rows(r), cols(c) {
//  postcondition: construct empty 2D mutex Matrix with size

    // Set rows of mutex matrix
    mutexes = new mutex * [rows];
    
    // Set cols of mutex matrix
    for (int i = 0; i < rows; i++){
        mutexes[i] = new mutex[cols];
    }
}


MutexMatrix::~MutexMatrix() {
//  postcondition: destruct 2D mutex Matrix
    
    Delete();
}


void MutexMatrix::Delete(void) {
//  postcondition: deletes all matrix
    
    // Deletes all cols of mutex matrix
    for (int i = 0; i<rows; i++){
        delete [] mutexes[i];
    }
    
    // Deletes all rows of mutex matrix
    delete [] mutexes;
}


void MutexMatrix::LockCell(int r, int c) {
//  postcondition: locks cell's mutex which given index
    
    return mutexes[r][c].lock();
}


void MutexMatrix::UnlockCell(int r, int c) {
//  postcondition: unlocks cell's mutex which given index

    return mutexes[r][c].unlock();
}


bool MutexMatrix::TrylockCell(int r, int c) {
//  postcondition: try locks cell's mutex which given index

    return mutexes[r][c].try_lock();
}
#endif /* _MUTEX_MATRIX_H */
