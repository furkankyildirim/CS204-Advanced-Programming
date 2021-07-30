//
//  Created by Furkan Kerim YILDIRIM on 19.07.2021.
//  furkanyildirim 28138

#include <iostream>
#include "Playlist.h"

using namespace std;

Playlist::Playlist(void){
// postcondition: construct empty Minesweeper
    
    head = NULL;    // define start of playlist is empty.
    tail = NULL;    // define end of playlist is empty.
}

bool Playlist::isExist(string name) const {
// postcondition: make sure that the song is already exist
    
    // make sure that the playlist is not empty.
    if (head == NULL && tail == NULL) return false;
    
    // define temp. song ptr.
    song *p = head;
    
    // search song name. if exist return true
    do {
        if (p->name == name) return true;
        else if (p->next == NULL) return false;
        p = p->next;
        
    } while (p != head);
    
    return false;
}

bool Playlist::isEmpty() const {
// postcondition: make sure that the playlist is empty.

    if (head == NULL && tail == NULL) return true;
    else return false;
}


void Playlist::addSong(string nm, string s, string g, int c, int d) {
// postcondition: add song to playlist

    // create new song
    song *temp = new song(nm, s, g, c, d,NULL,NULL);
    
    // if playlist is empty
    if (head == NULL && tail == NULL) {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
        tail = temp;   
    }
    
    // if new song should be added to end of playlist
    else if (tail->listenerCount > temp->listenerCount || (tail->listenerCount == temp->listenerCount && tail->name < temp->name)){
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        head->prev = tail;
        tail->next = head;
    }
    
    // if new song should be added to start of playlist
    else if (head->listenerCount < temp->listenerCount || (head->listenerCount == temp->listenerCount && head->name > temp->name)){
        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = tail;
        tail->next = head;
    }
    
    // if new song should be added to middle of playlist
    else {
        song * p = head->next;
        do {
            if (p->listenerCount < temp->listenerCount || (p->listenerCount == temp->listenerCount && p->name > temp->name)) {
                temp->next = p;
                temp->prev = p->prev;
                p->prev->next = temp;
                p->prev= temp;
                break;
            }
            p = p->next;
        } while (p != head);
    }
}

void Playlist::deleteSong(string name) {
// postcondition: delete song from playlist

    // if the song is at the start of the playlist
    if (head->name == name) {
        song *tmp = head;
        tail->next = tmp->next;
        tmp->next->prev = tail;
        head = tmp->next;
        delete tmp; tmp = NULL;
        cout << "The song " << name << " is deleted from the list." << endl;
        cout << "---" << endl;
        return;
    }
    
    // if the song is at the end of the playlist
    else if (tail->name == name) {
        song *tmp = tail;
        head->prev = tmp->prev;
        tmp->prev->next = head;
        tail = tmp->prev;
        delete tmp; tmp = NULL;
        cout << "The song " << name << " is deleted from the list." << endl;
        cout << "---" << endl;
        return;
    }
    
    // if the song is at the middle of the playlist
    song * p = head;
    do {
        if (p->name == name) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p; p = NULL;
            
            cout << "The song " << name << " is deleted from the list." << endl;
            cout << "---" << endl;
            return;
        }
        p = p->next;
    } while (p != head);
    
    cout << "The song " << name << " could not be found in the list." << endl;
    cout << "---" << endl;
}

void Playlist::printSongs(void) const {
// postcondition: print all songs from playlist acc. to list. count & name
    
    song *p = head;
    do {
        cout << "Song Name: " << p->name << endl;
        cout << "Singer Name: " << p->singer << endl;
        cout << "Genre: " << p->genre << endl;
        cout << "Duration: " << p->duration << endl;
        cout << "Listener Count: " << p->listenerCount << endl;
        cout << "---" << endl;
        p = p->next;
        
    } while (p != head);
}

void Playlist::printSongsReverse(void) const {
// postcondition: print reverse all songs from playlist acc. to list. count & name
    
    song *p = tail;
    do {
        cout << "Song Name: " << p->name << endl;
        cout << "Singer Name: " << p->singer << endl;
        cout << "Genre: " << p->genre << endl;
        cout << "Duration: " << p->duration << endl;
        cout << "Listener Count: " << p->listenerCount << endl;
        cout << "---" << endl;
        p = p->prev;
        
    } while (p != tail);
}

void Playlist::totalDuration(void) const {
// postcondition: print total duration on playlist
    
    song *p = head;
    int duration = 0;
    
    // calculate total duration
    do {
        duration += p->duration;
        p = p->next;
    } while (p != head);
    
    cout << "Enjoy your next " << duration << " minutes with the songs in the list." << endl;
    cout << "---" << endl;
}

void Playlist::printSongsSameGenres(string genre) const {
// postcondition: print songs from playlist acc. to genre
    
    song *p = head;
    cout << "List of All the Songs from Genre " << genre << endl;
    cout << "---" << endl;
    
    // print song if ptr genre is eq. to genre
    do {
        if (p->genre == genre) {
            cout << "- "<< p->name << " from " << p->singer << endl;
        }
        p = p->next;
    } while (p != head);
    cout << "---" << endl;
}

void Playlist::printSongsSameSinger(string singer) const {
// postcondition: print songs from playlist acc. to singer

    song *p = head;
    cout << "List of All the Songs from Singer " << singer << endl;
    cout << "---" << endl;
    
    // print song if ptr. singer is eq. to singer
    do {
        if (p->singer == singer) {
            cout << "- "<< p->name << endl;
        }
        p = p->next;
    } while (p != head);
    cout << "---" << endl;
}

void Playlist::deleteAll() {
// postcondition: delete all playlist

    // make sure that the playlist is not empty.
    if (head == NULL || tail == NULL) return;
    song *ptr = head;
    
    // delete all songs
    do {
        song *tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    } while (ptr != head && ptr != NULL);
    
    head = NULL;    // define start of playlist is empty.
    tail = NULL;    // define end of playlist is empty.
}

