//
//  Created by Furkan Kerim YILDIRIM on 19.07.2021.
//  furkanyildirim 28138

#include <iostream>
#include <string>
#include <cctype>       // for toupper
#include <sstream>      // for strinstream
#include "Playlist.h"   // Song List class
 

using namespace std;

string editInput(string & input) {
// postcondition: delete extra whitespace and uppercase all case
    
    // delete all whitespace
    string word, output;
    stringstream ss(input);
    ss >> output;
    
    // put a whitespace
    while (ss >> word) {
        output = output + ' ' + word;
    }
    
    // uppercase all case
    for(int i=0; i < output.length(); i++) {
        output[i] = toupper(output[i]);
    }

    return output;
}

int main() {
    
    // Show message and menu
    cout << "This program helps to create a music list and suggest you songs that you might like!" << endl;
    cout << "---" << endl;
    cout << "MENU" << endl;
    cout << "1. Add a song to the list" << endl;
    cout << "2. Delete a song from the list" << endl;
    cout << "3. Print the song list" << endl;
    cout << "4. Print the song list in reverse order" << endl;
    cout << "5. Show total duration of the list" << endl;
    cout << "6. Print songs from the same genre" << endl;
    cout << "7. Print songs from the same singer" << endl;
    cout << "8. Exit" << endl;
    cout << "---" << endl;
    
    // Define option variables and Playlist.
    string option, tmp;
    Playlist playlist = Playlist();
    
    // Get option input from user until the option is eq to 8
    while (option != "8") {
        
        // Get option input from user
        cout << "Enter your choice: ";
        cin >> option;
        getline(cin, tmp);
        cout << "---" << endl;
        
        // Add song to list option
        if (option == "1") {
            
            // Define varianles
            string name, singer, genre;
            int listenerCount, duration;
            
            // Get song name
            cout << "Enter the name of the song: ";
            getline(cin, name);
            
            // Make sure that song name is not exist
            if (!(playlist.isExist(editInput(name)))) {
                
                // Get singer name
                cout << "Enter singer name of the song: ";
                getline(cin, singer);
                
                // Get genre
                cout << "Enter genre of the song: ";
                getline(cin, genre);
                
                // Get listener count
                cout << "Enter the listener count of the song: ";
                cin >> listenerCount;
                
                // Get duration
                cout << "Enter the duration of the song: ";
                cin >> duration;
                
                // Add song to playlist
                playlist.addSong(editInput(name), editInput(singer), editInput(genre), listenerCount, duration);
                
                // Show message
                cout << "---" << endl;
                cout << "The song " << editInput(name) << " from " << editInput(singer) << " is added to the song list." << endl;
                cout << "---" << endl;
            }
            
            // Show message if song name is already exist.
            else {
                cout << "---" << endl;
                cout << "The song " << editInput(name) << " is already in the song list." << endl;
                cout << "---" << endl;
            }
        }
        
        // Delete song from playlist option
        else if (option == "2") {
    
            // Make sure that the playlist is not empty
            if (playlist.isEmpty()) {
                cout << "The song list is empty." << endl;
                cout << "---" << endl;
                
            } else {
                
                // Get song name
                string name;
                cout << "Enter the name of the song: ";
                getline(cin, name);
                
                // Delete song from playlist
                playlist.deleteSong(editInput(name));
            }
        }
        
        // Print song list option
        else if (option == "3") {
            
            // Make sure that the playlist is not empty
            if (playlist.isEmpty()) cout << "The song list is empty.\n---" << endl;
            
            // Print playlist
            else playlist.printSongs();
            
        }
        
        // Print reverse playlist option
        else if (option == "4") {
            
            // Make sure that the playlist is not empty
            if (playlist.isEmpty()) cout << "The song list is empty.\n---" << endl;
            
            // Print reverse playlist
            else playlist.printSongsReverse();
            
        }
        
        // Show total duration option
        else if (option == "5") {
            
            // Make sure that the playlist is not empty
            if (playlist.isEmpty()) cout << "The song list is empty.\n---" << endl;
            
            // Show total duration
            else playlist.totalDuration();
            
        }
        
        // Print songs from genre option
        else if (option == "6") {
            
            // Make sure that the playlist is not empty
            if (playlist.isEmpty()) {
                cout << "The song list is empty." << endl;
                cout << "---" << endl;
            }
            
            // Print songs from genre
            else {
                
                // Get genre
                string name;
                cout << "Please enter the genre of the songs you want to list: ";
                getline(cin, name);
                cout << "---" << endl;
                
                // Print songs from genre func.
                playlist.printSongsSameGenres(editInput(name));
            }
            
        }
        
        // Print songs from singer option
        else if (option == "7") {
            
            // Make sure that the playlist is not empty
            if (playlist.isEmpty()) {
                cout << "The song list is empty." << endl;
                cout << "---" << endl;
            }
            
            // Print songs from singer
            else {
                
                // Get singer name
                string name;
                cout << "Please enter the singer name of the songs you want to list: ";
                getline(cin, name);
                cout << "---" << endl;
                
                // Print songs from singer func.
                playlist.printSongsSameSinger(editInput(name));
            }
            
        }
        
        // Delete playlist and exit option.
        else if (option == "8") {
            
            // Delete playlist
            playlist.deleteAll();
            cout << "Deleting song list...\nExiting the program..." << endl;
        }
        
        // Invalid option
        else {
            cout << "Not a valid option." << endl;
            cout << "---" << endl;
        }
    }
    
    return 0;
}
