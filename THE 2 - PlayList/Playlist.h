//
//  Created by Furkan Kerim YILDIRIM on 19.07.2021.
//  furkanyildirim 28138

#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include <string>
using namespace std;

struct song {                                                                   // song information to be processed in the playlist
    
    // Variables
    string name, singer, genre;
    int listenerCount, duration;
    song *prev, *next;
    
    song(){}                                                                    // empty constructor;
    
    song (string nm, string s, string g, int c, int d, song * p, song * n) {    // valid constructor;
        name = nm; singer = s; genre = g;
        listenerCount = c; duration = d;
        prev = p; next = n;
    }
};

class Playlist {
public:
    
    Playlist(void);                                            // construct empty Playlist
    
    void    addSong(string nm, string s, string g, int c, int d)    ;   // add song to playlist
    void    deleteSong(string name)                                 ;   // delete song from playlist
    void    deleteAll(void)                                         ;   // delete all playlist
    void    totalDuration(void)                                const;   // print total duration on playlist
    void    printSongs(void)                                   const;   // print all songs from playlist acc. to list. count & name
    void    printSongsReverse(void)                            const;   // print reverse all songs from playlist acc. to list. count & name
    void    printSongsSameGenres(string genre)                 const;   // print songs from playlist acc. to genre
    void    printSongsSameSinger(string singer)                const;   // print songs from playlist acc. to singer
    
    bool    isExist(string name)                               const;   // make sure that the song is already exist
    bool    isEmpty(void)                                      const;   // make sure that the song list is empty.
    
private:
    song *head, *tail                                               ;    // start and end link of playlist
};

#endif /* _PLAYLIST_H */
