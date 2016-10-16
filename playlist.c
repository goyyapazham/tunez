#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "songz.h"
#include "playlist.h"

song_node *playlist = 0;

// ================== ADD    FXNS ==================
//add song to library in correct order
void add_song( char s[], char a[] ) {
  playlist = insert(playlist, s, a);
  printf("adding %s - %s...\n", a, s);
}
// ================== ADD    FXNS ==================




// ================== SEARCH FXNS ==================
//return ptr to specified song
void find_song(char s[]) {
  printf("looking for %s...\n", s);
  song_node *key = find_Song(playlist, s);
  if(key)
    printf("found %s - %s\n", key->artist, key->song);
  printf("\n");
}
//print songs by specified artist
void find_artist(char a[]) {
  printf("looking for %s...\n", a);
  find_a(a, "found ");
}
void find_a(char a[], char f[]) {
  song_node *key = find_Artist(playlist, a);
  if(key)
    while(strcmp(a, key->artist) == 0) {
      printf("%s%s - %s\n", f, key->artist, key->song);
      key = key->next;
    }
  printf("\n");
}
// ================== SEARCH FXNS ==================



// ================== PRINT  FXNS ==================
//print all entries under a certain letter
//void print_letter( char l );
//print all entries from a certain artist
void print_artist( char a[] ) {
  printf("%s list:\n", a);
  find_a(a, "* ");
}
//print entire list
void print_library() {
  print_list(playlist);
}
// ================== PRINT  FXNS ==================
