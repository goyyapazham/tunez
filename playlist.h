#include "songlist.h"

song_node *table[26];

// ================== ADD    FXNS ==================
//add song to library in correct order
void add_song( char song[], char artist[] ); //DONE

// ================== SEARCH FXNS ==================
//return ptr to specified song
song_node * find_song(char song[]); //DONE
//return ptr to first song by specified artist
song_node * find_artist(char artist[]); //DONE

// ================== PRINT  FXNS ==================
//print all entries under a certain letter
void print_letter( char letter ); //DONE
//print all entries from a certain artist
void print_artist( char artist[] ); //DONE
//print entire library
void print_library(); //DONE
//print shuffled library
void shuffle();

// ================== DELETE FXNS ==================
//delete specified song
void delete_song( char song[], char artist[] ); //DONE
//delete entire library
void delete_library(); //DONE
