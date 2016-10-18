#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

// ================== ADD    FXNS ==================
//add song to library in correct order
void add_song( char s[], char a[] ) {
  printf("adding %s - %s...\n", a, s);
  char letter = a[0]-97;
  table[letter] = insert(table[letter], s, a);
}
// ================== ADD    FXNS ==================



// ================== SEARCH FXNS ==================
//print specified song, if it exists
song_node * find_song(char s[]) {
  int i=0;
  song_node *tmp = 0;
  while(!tmp && i++ < 26)
    tmp = find_Song(table[i], s, "");
  print(tmp);
  return tmp;
}
//print songs by specified artist, if it exists
song_node * find_artist(char a[]) {
  song_node *tmp = table[a[0]-97];
  tmp = find_Artist(tmp, a);
  return tmp;
}
// ================== SEARCH FXNS ==================



// ================== PRINT  FXNS ==================
//print all entries under a certain letter
void print_letter( char l ) {
  printf("%c list:", l);
  print_list(table[l-97]);
  printf("\n\n");
}
//print all entries from a certain artist
void print_artist( char a[] ) {
  printf("%s list:\n", a);
  song_node *l = find_artist(a);
  while(l && strncmp(a, l->artist, 1) == 0) {
    if(strcmp(l->artist, a) == 0)
      printf("* %s - %s\n", l->artist, l->song);
    l = l->next;
  }
  printf("\n");
}
//print entire list
void print_library() {
  printf("\nyour library:");
  int i=0;
  while(i++ < 26)
    print_list(table[i]);
}
//print shuffled list
void shuffle() {
  printf("shuffling playlist...\n");
  //deep copy table into more easily shuffle-able songlist
  song_node *tmp = 0; int i=0;
  while(i++ < 26) {
    song_node *a = table[i];
    while(a) {
      tmp = insert_front(tmp, a->song, a->artist);
      a = a->next;
    }
  }
  //shuffle/whittle down songlist
  while(tmp) {
    song_node *rand = find_random(tmp);
    printf("%s - %s\n", rand->artist, rand->song);
    tmp = remove_song(tmp, rand->song, rand->artist);
  }
  printf("\n");
}
// ================== PRINT  FXNS ==================



// ================== DELETE FXNS ==================
//delete specified song
void delete_song( char s[], char a[] ) {
  printf("\n\ndeleting %s - %s...", a, s);
  table[a[0]-97] = remove_song(table[a[0]-97], s, a);
  print_library();
}
//delete entire library
void delete_library() {
  int i=0;
  while(i++ < 26)
    table[i] = free_list(table[i]);
}
// ================== DELETE FXNS ==================
