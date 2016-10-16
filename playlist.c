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
//print specified song, if it exists
void find_song(char s[]) {
  printf("looking for %s...\n", s);
  song_node *key = find_Song(playlist, s);
  if(key)
    printf("found %s - %s\n", key->artist, key->song);
  printf("\n");
}
//print songs by specified artist, if it exists
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
//return ptr to first song by first artist beginning with specified letter
song_node * find_l(char l) {
  
  song_node *tmp = playlist;

  while( tmp->next ) {
    if( strncmp(&l, tmp->artist, 1) == 0 )
      return tmp;
    tmp = tmp->next;
  }

  printf("Letter not found.\n");
  return 0;
  
}
// ================== SEARCH FXNS ==================



// ================== PRINT  FXNS ==================
//print all entries under a certain letter
void print_letter( char l ) {
  printf("%c list:\n", l);
  song_node *tmp = find_l(l);
  while(tmp && strncmp(&l, tmp->artist, 1) == 0) {
    printf("* %s - %s\n", tmp->artist, tmp->song);
    tmp = tmp->next;
  }
  printf("\n");
}
//print all entries from a certain artist
void print_artist( char a[] ) {
  printf("%s list:\n", a);
  find_a(a, "* ");
}
//print entire list
void print_library() {
  print_list(playlist);
  printf("\n");
}
//print shuffled list
void shuffle() {
  printf("shuffling playlist...\n");
  song_node *tmp = (song_node *)malloc(sizeof(song_node *));
  song_node *tmp2 = playlist;
  int i=0;
  while(tmp2) {
    tmp = insert_front(tmp, tmp2->song, tmp2->artist);
    tmp2 = tmp2->next;
  }
  while(tmp) {
    song_node *rand = find_random(tmp);
    printf("%s - %s\n", rand->artist, rand->song);
    remove_song(tmp, rand->song, rand->artist);
  }
  printf("\n");
}
// ================== PRINT  FXNS ==================




// ================== DELETE FXNS ==================
//delete specified song
void delete_song( char s[], char a[] ) {
  printf("deleting %s - %s...\n", a, s);
  playlist = remove_song(playlist, s, a);
  printf("\n");
}
//delete entire library
void delete_library() {
  free_list(playlist);
}
// ================== DELETE FXNS ==================
