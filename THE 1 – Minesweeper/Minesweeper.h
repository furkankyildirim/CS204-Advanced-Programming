//
//  Created by Furkan Kerim YILDIRIM on 7.07.2021.
//  furkanyildirim 28138

#ifndef _MINESWEEPER_H
#define _MINESWEEPER_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Minesweeper
{
public:
    Minesweeper();                              // construct empty Minesweeper
    Minesweeper(int rowSize, int columnSize);   // construct Minesweeper with specified sizes
    
    void openCell(int row, int column)              ;   // open cell in specified index
    void markBomb(int row, int column)              ;   // mark bomb in specified index
    void help()                                     ;   // get help to find bomb
    void check()                                    ;   // make sure the game is going on
    void showAll()                             const;   // show the Minesweeper
    
    void setItem(int row, int column, char item)    ;   // set mine in specified index
    void setState(int num)                          ;   // set game state: 1 -> won; 2 -> continues; 3-> lost
    void setRowSize(int row)                        ;   // set row size of Minesweeper
    void setColumnSize(int column)                  ;   // set column size of Minesweeper
    
    char getItem(int row, int column)          const;   // return cell's item in specified index
    int  getState()                            const;   // return game status: 1 -> won; 2 -> continues; 3-> lost
    int  getRowSize()                          const;   // return row size of Minesweeper
    int  getColumnSize()                       const;   // return column size of Minesweeper
    
private:
    struct cell {
        char status = '.';                              // define a struct that includes the item which
        char item;                                      // has a mine and, state when displaying
        
        cell(){}                                // construct cell struct
    };
    
    struct index {                                      // define a struct for showing the specified index
        int row = -1;
        int column = -1;
        
        index(){}                               // construct index struct
    };
    
    vector<vector<cell> > mns;
    

    int   bombCount(int row, int column)            ;   // return bomb count of neighbors of specified index
    bool  checkIndex(int row, int column)           ;   // make sure that cell index is valid
    bool  isClosed(int row, int column)             ;   // make sure the neighbor of the specified index is closed
    index hasBomb(int row, int column)              ;   // return bomb index of the neighbor of the specified index
    
    
    int helpEntitlement = 3                         ;   // the right to the remaining help
    int rSize, cSize                                ;   // cell Minesweeper row size and column size
    int state = 0                                   ;   // game state: 1 -> won; 2 -> continues; 3-> lost
    
};

#endif /* _MINESWEEPER_H */
