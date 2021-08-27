//
//  Created by Furkan Kerim YILDIRIM on 13.08.2021.
//  furkanyildirim 28138

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include "Matrix.h"
#include "MutexMatrix.h"

using namespace std;

mutex coutMutex;                                            //  mutex for cout

struct indexes{                                             //  to send matrix cell index between transactions
    int row, col;
    
    indexes(){}                                             //  default constructor
    indexes(int r = 0, int c = 0): row(r), col(c) {}        //  valid constructor
};

void openFile(ifstream & file) {
//  postcondition: return file the user wants to read

    string name;
    
    // Get filename until open successfully
    do{
        cout << "Please enter a file name for the matrix: ";
        cin >> name;
        file.clear();
        file.open(name.c_str());
    }while(file.fail());
}

Matrix fillMatrix(ifstream & file) {
//  postcondition: return new filled matrix

    int rowSize, columnSize, value;
    string line;
    
    // Get row and column size
    getline(file, line);
    stringstream ss(line);
    ss >> rowSize >> columnSize;
    
    // Define Matrix
    Matrix matrix = Matrix(rowSize,columnSize);
    
    // Fill the Matrix;
    for (int i = 0; i < rowSize; i++) {
        getline(file, line);
        stringstream ss(line);
        
        for (int j = 0; j < columnSize; j++) {
            ss >> value;
            matrix.SetIndex(i, j, value);
        }
    }
    
    // Close the file;
    file.close();
    
    return matrix;
}

void setBalance(int r, int c, string position, int & mx, int & cell) {
//  postcondition: adjusts the balance between two neighboring cells and prints message
    
    // Define value to transfer between neighbors
    int value;
    if (cell % 3 == 0) value = cell / 3;
    else value = cell / 3 + 1;
    
    // Print the process message
    coutMutex.lock();
    cout << "Row-" << r << ",Col-" << c << " (" << cell << ") is incremented by " << value;
    cout << " by stealing from the cell to the " << position << " (" << mx << ")." << endl;
    coutMutex.unlock();
    
    // Transfer value between neighbors
    cell += value;
    mx -= value;
}

void lock3Mutex(MutexMatrix & mutexes, indexes i1, indexes i2, indexes i3) {
//  postcondition: tries to lock the 3 mutexes whose indexes were sent until successfully locked.

    while (true) {
        
        // Try to lock mutexes.
        bool checker1 = mutexes.TrylockCell(i1.row, i1.col);
        bool checker2 = mutexes.TrylockCell(i2.row, i2.col);
        bool checker3 = mutexes.TrylockCell(i3.row, i3.col);
        
        // If all mutexes were locked finish; else unlock mutexes, yield the thread and try again.
        if (checker1 && checker2 && checker3) break;
        else {
            if (checker1) mutexes.UnlockCell(i1.row, i1.col);
            if (checker2) mutexes.UnlockCell(i2.row, i2.col);
            if (checker3) mutexes.UnlockCell(i3.row, i3.col);
            this_thread::yield();
        }
    }
}

void lock4Mutex(MutexMatrix & mutexes, indexes i1, indexes i2, indexes i3, indexes i4) {
//  postcondition: tries to lock the 4 mutexes whose indexes were sent until successfully locked.

    while (true) {
        
        // Try to lock mutexes
        bool checker1 = mutexes.TrylockCell(i1.row, i1.col);
        bool checker2 = mutexes.TrylockCell(i2.row, i2.col);
        bool checker3 = mutexes.TrylockCell(i3.row, i3.col);
        bool checker4 = mutexes.TrylockCell(i4.row, i4.col);
        
        // If all mutexes were locked finish; else unlock mutexes, yield the thread and try again
        if (checker1 && checker2 && checker3 && checker4) break;
        else {
            if (checker1) mutexes.UnlockCell(i1.row, i1.col);
            if (checker2) mutexes.UnlockCell(i2.row, i2.col);
            if (checker3) mutexes.UnlockCell(i3.row, i3.col);
            if (checker4) mutexes.UnlockCell(i4.row, i4.col);
            this_thread::yield();
        }
    }
}

void lock5Mutex(MutexMatrix & mutexes, indexes i1, indexes i2, indexes i3, indexes i4, indexes i5) {
//  postcondition: tries to lock the 5 mutexes whose indexes were sent until successfully locked.

    while (true) {
        
        // Try to lock mutexes
        bool checker1 = mutexes.TrylockCell(i1.row, i1.col);
        bool checker2 = mutexes.TrylockCell(i2.row, i2.col);
        bool checker3 = mutexes.TrylockCell(i3.row, i3.col);
        bool checker4 = mutexes.TrylockCell(i4.row, i4.col);
        bool checker5 = mutexes.TrylockCell(i5.row, i5.col);
        
        // If all mutexes were locked finish; else unlock mutexes, yield the thread and try again.
        if (checker1 && checker2 && checker3 && checker4 && checker5) break;
        else {
            if (checker1) mutexes.UnlockCell(i1.row, i1.col);
            if (checker2) mutexes.UnlockCell(i2.row, i2.col);
            if (checker3) mutexes.UnlockCell(i3.row, i3.col);
            if (checker4) mutexes.UnlockCell(i4.row, i4.col);
            if (checker5) mutexes.UnlockCell(i5.row, i5.col);
            this_thread::yield();
        }
    }
}

void unlock3Mutex(MutexMatrix & mutexes, indexes i1, indexes i2, indexes i3) {
//  postcondition: unlock 3 mutexes whose indexes were sent
    
    mutexes.UnlockCell(i1.row, i1.col);
    mutexes.UnlockCell(i2.row, i2.col);
    mutexes.UnlockCell(i3.row, i3.col);
}

void unlock4Mutex(MutexMatrix & mutexes, indexes i1, indexes i2, indexes i3, indexes i4) {
//  postcondition: unlock 4 mutexes whose indexes were sent

    mutexes.UnlockCell(i1.row, i1.col);
    mutexes.UnlockCell(i2.row, i2.col);
    mutexes.UnlockCell(i3.row, i3.col);
    mutexes.UnlockCell(i4.row, i4.col);
}

void unlock5Mutex(MutexMatrix & mutexes, indexes i1, indexes i2, indexes i3, indexes i4, indexes i5) {
//  postcondition: unlock 5 mutexes whose indexes were sent

    mutexes.UnlockCell(i1.row, i1.col);
    mutexes.UnlockCell(i2.row, i2.col);
    mutexes.UnlockCell(i3.row, i3.col);
    mutexes.UnlockCell(i4.row, i4.col);
    mutexes.UnlockCell(i5.row, i5.col);
}

void neighborIsMax(int *& max, string & position , string str, indexes index, Matrix & matrix) {
//  postcondition: make sure that given matrix cell index is bigger than current maximum index
    
    // Get given matrix cell index value and compare
    if (*max < matrix.GetIndex(index.row, index.col)) {
        
        // Set new maximum index reference from given matrix cell
        max = &matrix.GetRef(index.row, index.col);
        
        // Set new position string from given string
        position = str;     // "above", "bellow", "right", "left"
    }
}

void operation(Matrix & matrix, MutexMatrix & mutexes, int index){
//  postcondition: Get matrix and mutexes classes and, works to adjusts the balance between its neighbors from index

    // Define the iter. to set current row and col
    MatrixItr matrixItr (matrix);
    int row = index / matrixItr.cols;
    int col = index % matrixItr.cols;
    
    // Set the current matrix cell reference and define max neighbor reference
    int *cell = & matrix.GetRef(row, col);
    int * max = cell;
    
    // Define position string -> "above", "bellow", "right", "left"
    string position;

    if (row == 0) {
        
        // When the current matrix cell position is top left corner
        if (col == 0) {
            
            // Lock the neighbor mutexes
            lock3Mutex(mutexes, indexes(row, col), indexes(row+1, col), indexes(row, col+1));
            
            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "bellow", indexes(row+1, col), matrix);
            neighborIsMax(max, position, "right", indexes(row, col+1), matrix);
                            
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock3Mutex(mutexes, indexes(row, col), indexes(row+1, col), indexes(row, col+1));
        }
        
        // When the current matrix cell position is top right corner
        else if (col == matrixItr.cols - 1) {
            
            // Lock the neighbor mutexes
            lock3Mutex(mutexes, indexes(row, col), indexes(row+1, col), indexes(row, col-1));

            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "bellow", indexes(row+1, col), matrix);
            neighborIsMax(max, position, "left", indexes(row, col-1), matrix);
                           
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock3Mutex(mutexes, indexes(row, col), indexes(row+1, col), indexes(row, col-1));
        }
        
        // When the current matrix cell position is top line
        else {
            
            // Lock the neighbor mutexes
            lock4Mutex(mutexes,indexes(row, col), indexes(row+1, col), indexes(row, col+1), indexes(row, col-1));
            
            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "bellow", indexes(row+1, col), matrix);
            neighborIsMax(max, position, "right", indexes(row, col+1), matrix);
            neighborIsMax(max, position, "left", indexes(row, col-1), matrix);

            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock4Mutex(mutexes,indexes(row, col), indexes(row+1, col), indexes(row, col+1), indexes(row, col-1));
        }
        
    } else if (row == matrixItr.rows -1) {
        
        // When the current matrix cell position is bottom left corner
        if (col == 0) {
            
            // Lock the neighbor mutexes
            lock3Mutex(mutexes, indexes(row, col), indexes(row-1, col), indexes(row, col+1));
            
            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "above", indexes(row-1, col), matrix);
            neighborIsMax(max, position, "right", indexes(row, col+1), matrix);
            
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock3Mutex(mutexes, indexes(row, col), indexes(row-1, col), indexes(row, col+1));
        }
        
        // When the current matrix cell position is bottom right corner
        else if (col == matrixItr.cols - 1) {
            
            // Lock the neighbor mutexes
            lock3Mutex(mutexes, indexes(row, col), indexes(row-1, col), indexes(row, col-1));
            
            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "above", indexes(row-1, col), matrix);
            neighborIsMax(max, position, "left", indexes(row, col-1), matrix);
            
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock3Mutex(mutexes, indexes(row, col), indexes(row-1, col), indexes(row, col-1));
        }
        
        // When the current matrix cell position is bottom line
        else {
            
            // Lock the neighbor mutexes
            lock4Mutex(mutexes,indexes(row, col), indexes(row-1, col), indexes(row, col+1), indexes(row, col-1));
            
            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "above", indexes(row-1, col), matrix);
            neighborIsMax(max, position, "right", indexes(row, col+1), matrix);
            neighborIsMax(max, position, "left", indexes(row, col-1), matrix);
            
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock4Mutex(mutexes,indexes(row, col), indexes(row-1, col), indexes(row, col+1), indexes(row, col-1));
        }
        
    } else {
        
        // When the current matrix cell position is left line
        if (col == 0) {
            
            // Lock the neighbor mutexes
            lock4Mutex(mutexes,indexes(row, col), indexes(row+1, col), indexes(row-1, col), indexes(row, col+1));

            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "above", indexes(row-1, col), matrix);
            neighborIsMax(max, position, "right", indexes(row, col+1), matrix);
            neighborIsMax(max, position, "bellow", indexes(row+1, col), matrix);
                           
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock4Mutex(mutexes,indexes(row, col), indexes(row+1, col), indexes(row-1, col), indexes(row, col+1));
        }
        
        // When the current matrix cell position is right line
        else if (col == matrixItr.cols - 1) {
            
            // Lock the neighbor mutexes
            lock4Mutex(mutexes,indexes(row, col), indexes(row+1, col), indexes(row-1, col), indexes(row, col-1));
            
            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "bellow", indexes(row+1, col), matrix);
            neighborIsMax(max, position, "above", indexes(row-1, col), matrix);
            neighborIsMax(max, position, "left", indexes(row, col-1), matrix);
            
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock4Mutex(mutexes, indexes(row, col), indexes(row+1, col), indexes(row-1, col), indexes(row, col-1));

        }
        
        // When the current matrix cell position is not border
        else {
            
            // Lock the neighbor mutexes
            lock5Mutex(mutexes,indexes(row, col), indexes(row+1, col), indexes(row-1, col), indexes(row, col+1), indexes(row, col-1));
            
            // Find the neighbor that have biggest value and set the message position
            neighborIsMax(max, position, "bellow", indexes(row+1, col), matrix);
            neighborIsMax(max, position, "above", indexes(row-1, col), matrix);
            neighborIsMax(max, position, "right", indexes(row, col+1), matrix);
            neighborIsMax(max, position, "left", indexes(row, col-1), matrix);
                            
            // Make sure that the big value is big enough and set balance
            if (*max >= 2 * *cell) setBalance(row, col, position, *max, *cell);
            
            // Unlock the neighbor mutexes
            unlock5Mutex(mutexes,indexes(row, col), indexes(row+1, col), indexes(row-1, col), indexes(row, col+1), indexes(row, col-1));
        }
    }
}

int main() {
    cout << "Welcome to the last assignment :(" << endl;
    
    // open the file
    ifstream file;
    openFile(file);
    
    // Read file and fill matrix, old matrix matrix iter. and mutex matrix
    Matrix matrix = fillMatrix(file);
    MatrixItr matrixItr (matrix);
    Matrix oldMatrix (matrixItr.rows, matrixItr.cols);
    MutexMatrix mutexes (matrixItr.rows, matrixItr.cols);
    
    // Print original matrix
    cout << "-----" << endl;
    cout << "Printing the original matrix:" << endl;
    matrix.Print();

    // Define matrix size and create thread list for all matrix cell
    #define CELLS_NUM matrixItr.rows * matrixItr.cols
    thread threads[CELLS_NUM];
    
    // Run threads until matrix and ol matrix is the same
    while (!matrix.Equals(oldMatrix)) {
        cout << "-----" << endl;
        cout << "A new round starts" << endl;
        
            // Set old matrix
            oldMatrix = matrix;
        
            // Run threads, send referances and set matrix balance
            for (int i = 0; i < CELLS_NUM; i++) {
                threads[i] = thread(&operation, ref(matrix), ref(mutexes), i);
            }
            
            // Join all threads
            for (int i = 0; i < CELLS_NUM; i++) {
                if (threads[i].joinable()) {
                    threads[i].join();
                }
            }
        
        // Make sure that matrix and old matrix are equal with each other
        if (!matrix.Equals(oldMatrix)) {
            cout << "The round ends with updates." << endl;
            cout << "Printing the matrix after the updates:" << endl;
            matrix.Print();
        } else {
            cout << "The round ends without updates." << endl;
            cout << "-----" << endl;
            break;
        }
    }

    cout << "Program is exiting..." << endl;

    return 0;
}
 
