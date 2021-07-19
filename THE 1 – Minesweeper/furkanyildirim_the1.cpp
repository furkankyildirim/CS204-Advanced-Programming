//
//  Created by Furkan Kerim YILDIRIM on 7.07.2021.
//  furkanyildirim 28138

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Minesweeper.h"

using namespace std;

Minesweeper fillMatrix (ifstream & file){
// postcondition: read the file, fill the matrix and return matrix you filled

    int rowSize, columnSize;
    string line;
    char chr;
    
    // Get row and column Size
    getline(file, line);
    stringstream ss(line);
    ss >> rowSize >> columnSize;
    
    // Define Minesweeper
    Minesweeper mns = Minesweeper(rowSize,columnSize);
    
    // Fill the Minesweeper;
    for (int i = 0; i < rowSize; i++) {
        getline(file, line);
        stringstream ss(line);
        
        for (int j = 0; j < columnSize; j++) {
            ss >> chr;
            mns.setItem(i, j, chr);
        }
    }
    
    // Close the file;
    file.close();
    
    return mns;
}


ifstream openFile(){
// postcondition: return file the user wants to read
    
    ifstream file;
    string filename, line;
    
    // Get filename;
    cout << "Enter the input file name: ";
    getline(cin, line);
    istringstream ss(line);
    ss >> filename;
    
    // Open the file
    file.open(filename.c_str());
    return file;
}


int main() {
    
    // Define Minesweeper and file variables.
    Minesweeper mns;
    ifstream file;
    
    // Open file successfully
    file = openFile();
    while (file.fail()) {
        cout << "Problem occurred while reading the file!!!" << endl;
        file = openFile();
    }
    
    cout << "Welcome to the Minesweeper Game!" << endl;
    cout << "You may choose a cell to open (-o), get help (-h) or mark/unmark bomb (-b)!!" << endl;
    
    
    // Read file and fill the Minesweeper
    mns = fillMatrix(file);
    mns.showAll();
    
    // Run as long as the game continues
    while (mns.getState() == 0) {
    
        string option, tmp;
        string row, column;
        
        // Get the inputs
        cout << "Please enter your choice: ";
        cin >> option;
        
        // Open cell
        if (option == "-o") {
            cin >> row >> column;
            
            // Make sure that valid coordinate
            if (isdigit(row[0]) && isdigit(column[0])){
                mns.openCell(stoi(row), stoi(column));
            } else {
                cout << "Please enter a valid coordinate! " << endl;
            }
            
        }
        // Mark bomb
        else if (option == "-b"){
            cin >> row >> column;
            
            // Make sure that valid coordinate
            if (isdigit(row[0]) && isdigit(column[0])){
                mns.markBomb(stoi(row), stoi(column));
            } else {
                cout << "Please enter a valid coordinate! " << endl;
            }
        
        } 
        // Help
        else if (option == "-h") {
            mns.help();

        } else {
            cout << "Invalid choice!!" << endl;
            
        }
        
        mns.check();
        getline(cin,tmp);
    }
    
    return 0;
}
