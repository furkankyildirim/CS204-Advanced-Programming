//
//  Created by Furkan Kerim YILDIRIM on 7.07.2021.
//  furkanyildirim 28138

#include "Minesweeper.h"
#include <iomanip>
#include <string>


Minesweeper::Minesweeper(){
// postcondition: construct empty Minesweeper
    
    mns = vector<vector<cell> > ();
}


Minesweeper::Minesweeper(int rowSize, int columnSize) {
// postcondition: construct Minesweeper with specified sizes
    
    mns = vector<vector<cell> > (rowSize,vector<cell>(columnSize));
    
    // set rowSize and column size of Minesweeper
    cSize = columnSize;
    rSize = rowSize;
}


char Minesweeper::getItem(int row, int column) const {
// postcondition: return cell's item in specified index
    
    return mns[row][column].item;
}


void Minesweeper::setItem(int row, int column, char item) {
// postcondition: set mine in specified index
    
    mns[row][column].item = item;
}


int Minesweeper::getState() const {
// postcondition: return game status: 1 -> won; 2 -> continues; 3-> lost
    
    return state;
}


void Minesweeper::setState(int num) {
// postcondition: set game state: 1 -> won; 2 -> continues; 3-> lost
    
    state = num;
}


int Minesweeper::getRowSize() const {
// postcondition: return row size of Minesweeper
    
    return rSize;
}


int Minesweeper::getColumnSize() const {
// postcondition: return row column of Minesweeper
    
    return cSize;
}


void Minesweeper::setRowSize(int row) {
// postcondition: set row size of Minesweeper
    
    rSize = row;
}


void Minesweeper::setColumnSize(int column) {
// postcondition: set column size of Minesweeper
    
    cSize = column;
}


void Minesweeper::showAll() const {
// postcondition: show the Minesweeper
    
    for (vector<cell> row : mns) {
        for (cell item: row) {
            cout << setw(4) << item.status;
        }
        cout << endl;
    }
    cout << '\n' <<endl;
}


bool Minesweeper::checkIndex(int row, int column) {
// postcondition: make sure that cell index is valid
    
    if (row >= 0 && row < rSize && column >= 0 && column < cSize) return true;
    else return false;
}


bool Minesweeper::isClosed(int row, int column) {
// postcondition: make sure the neighbor of the specified index is closed
    
    for (int i = row - 1; i < row + 2; i++) {
        for (int j = column -1; j < column + 2; j++) {
            
            if (checkIndex(i, j)) {
                if (mns[i][j].item != 'x' && mns[i][j].status == '.') return true;
            }
        }
    }
    return false;
}


Minesweeper::index Minesweeper::hasBomb(int row, int column) {
// postcondition: return bomb index of the neighbor of the specified index
    
    index idx;
    
    for (int i = row - 1; i < row + 2; i++) {
        for (int j = column -1; j < column + 2; j++) {
            
            if (checkIndex(i, j) && mns[i][j].item == 'x' && mns[i][j].status == '.') {
                idx.row = i; idx.column = j;
                return idx;
            }
        }
    }
    return idx;
}


int Minesweeper::bombCount(int row, int column) {
// postcondition: return bomb count of neighbors of specified index
    
    int bombCount = 0;
    
    for (int i = row - 1; i < row + 2; i++) {
        for (int j = column -1; j < column + 2; j++) {
            
            if (checkIndex(i, j)) {
                if (mns[i][j].item == 'x') bombCount++;
            }
        }
    }
    return bombCount;
}


void Minesweeper::check() {
// postcondition: make sure the game is going on
    
    // Open cell check
    for (int i = 0; i < rSize; i++) {
        for (int j = 0; j < cSize; j++) {
            if (mns[i][j].status == '.') return;
        }
    }

    // Marked bomb check
    for (int i = 0; i < rSize; i++) {
        for (int j = 0; j < cSize; j++) {
            if (mns[i][j].status == 'B' && mns[i][j].item != 'x' ) {
                cout << "You put bombs in the wrong places! Game over:(" << endl;
                setState(-1);
                return;
            }
        }
    }
    
    cout << "Congrats! You won!" << endl;
    setState(1);
}


void Minesweeper::help() {
// postcondition: get help to find bomb
    
    // Help right check
    if (!(helpEntitlement > 0)) {
        cout <<"Your help chances are over. :(" << endl;
        return;
    }

    
    for (int i = 0; i < rSize; i++) {
        for (int j = 0; j < cSize; j++) {
            cell *p = &mns[i][j];
            if (p->status > '0' && p->status < '9') {
                index idx = hasBomb(i, j); // make sure that the cell neighbor has bomb
                int xRow = idx.row, xCol = idx.column;
                if (xRow > -1 && xCol >-1) {
                    if (isClosed(xRow, xCol)) { // make sure that the cell neighbor is closed
                        mns[xRow][xCol].status = 'x';
                        helpEntitlement--; showAll();
                        return;
                    }
                }
            }
        }
    }
    
    helpEntitlement--;
    cout << "I can't help you." << endl;
}


void Minesweeper::openCell(int row, int column) {
// postcondition: open cell in specified index
    
    cell *p = &mns[row][column];
    
    // Valid coordinate check
    if (row >= rSize || column >= cSize) {
        cout << "Please enter a valid coordinate! " << endl;
    }
    
    //Mine check
    else if (p->status == '.' && p->item == 'x') {
        cout << "You opened a mine! Game over:(" << endl;
        setState(-1);
        
    // Marked bomb check
    } else if (p->status == 'B'){
        cout << "It seems like this cell is a bomb." << endl;
    
    // Open cell
    } else if (p->status == '.' && p->item == '-') {
        
        p->status = to_string(bombCount(row, column))[0];
        
        // If any neighbor of the cell does not contain a bomb
        if (p->status == '0') {
            for (int i = row - 1; i < row + 2; i++) {
                for (int j = column -1; j < column + 2; j++) {
                    if (checkIndex(i, j)) {
                        p = & mns[i][j];
                        p ->status = to_string(bombCount(i, j))[0];
                    }
                }
            }
        }
        
        // Print Minesweeper
        showAll();
    } else {
        cout << "Already opened." << endl;
    }
}


void Minesweeper::markBomb(int row, int column) {
// postcondition: mark bomb in specified index
    
    cell *p = &mns[row][column];
    
    // Valid coordinate check
    if (row >= rSize || column >= cSize) {
        cout << "Please enter a valid coordinate! " << endl;
    }
    
    // Mark bomb
    else if (p->status == '.') {
        p->status = 'B';
        showAll();
    }
    
    // Remove marked bomb
    else if (p->status == 'B') {
        p->status = '.';
        showAll();
    } else {
        cout << "Can't mark that cell as a bomb." << endl;
    }
}
