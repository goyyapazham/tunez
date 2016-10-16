#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "songz.h"

// ================== INSERT FXNS ==================
//insert new song to front of list, return ptr to front of list
song_node * insert_front( song_node *sn, char s[], char a[] ) {

  song_node *new = (song_node *)malloc(sizeof(song_node));

  new->next = sn;
  strcpy(new->song, s);
  strcpy(new->artist, a);

  return new;
}

//insert new song to list alphabetically, return ptr to front of list
song_node * insert( song_node *sn, char s[], char a[] ) {
  song_node *tmp = sn;
  return insert_ordered(tmp, s, a);
}

song_node * insert_ordered( song_node *sn, char s[], char a[] ) {
  
  //BASE CASE #1: list is empty
  if( !sn )
    return insert_front(sn, s, a);
  
  //BASE CASE #2: recursively reached artist ahead of me in ABC order
  if( strcmp(a, sn->artist) < 0 )
    return insert_front(sn, s, a);
  
  //BASE CASE #3: recursively reached my artist, song ahead of me in ABC order
  if( strcmp(a, sn->artist) == 0 && strcmp(s, sn->song) < 0 )
    return insert_front(sn, s, a);
  
  //RECURSIVE CALL: call fxn on next node
  else
    sn->next = insert(sn->next, s, a);
  
  return sn;
}
// ================== INSERT FXNS ==================



// ================== PRINT  FXNS ==================
void print_list( song_node *sn ) {
  printf("SONGS:\n");
  
  while(sn) {
    printf("%s - %s\n", sn->artist, sn->song);
    sn = sn->next;
  }
}
// ================== PRINT  FXNS ==================



// ================== SEARCH FXNS ==================
//search list, & return ptr to, first song w/ specified name
song_node * find_Song(song_node *sn, char s[]) {
  
  song_node *tmp = sn;
  
  //BASE CASE #1: list is empty
  if( !tmp )
    printf("Song not found.\n");

  //BASE CASE #2: song found (cannot be optimized more than this, because list
  //              is sorted first by artist)
  //             (also assume that no two songs can have the same name)
  else if( strcmp(s, tmp->song) == 0 )
    return tmp;

  //RECURSIVE CALL: test next node
  else
    return find_Song(tmp->next, s);

  //if not found
  return 0;
}

//search list, & return ptr to, first song by specified artist
song_node * find_Artist(song_node *sn, char a[]) {

  song_node *tmp = sn;

  //BASE CASE #1: list is empty
  if( !tmp )
    printf("Artist not found.\n");

  //BASE CASE #2: recursively reached first existing artist ahead of me in ABC order
  //              without reaching my artist
  else if( strcmp(a, tmp->artist) < 0 )
    printf("Artist not found.\n");

  //BASE CASE #3: artist found
  else if( strcmp(a, tmp->artist) == 0 )
    return tmp;

  //RECURSIVE CALL: test next node
  else
    return find_Artist(tmp->next, a);

  //if not found
  return 0;
  
}
//return length of list (needed for find_random)
int len(song_node *sn) {
  
  int i=0;
  
  while(sn) {
    sn = sn->next;
    i++;
  }
  
  return i;
  
}
//return ptr to random song in list
song_node * find_random(song_node *sn) {

  song_node *tmp = sn;
  
  int r = rand() % len(tmp);
  
  while(r) {
    tmp = tmp->next;
    r--;
  }

  return tmp;
  
}

// ================== SEARCH FXNS ==================




// ================== REMOVE FXNS ==================
//remove specified song from list, return ptr to front of list
song_node * remove_song(song_node *sn, char s[], char a[]) {

  song_node *tmp = sn;
  if( !tmp ) {
    return sn;
  }

  //printf("TMP\n");
  //print_list(tmp);

  song_node *tmps = find_Song(tmp, s);
  if( !tmps ) {
    return sn;
  }

  if(tmp == tmps) {
    //printf("TMP->NEXT\n");
    //print_list(tmp->next);
    return tmp->next;
  }

  song_node *prv = 0;
  while(tmp->next && tmp != tmps) {
    prv = tmp;
    tmp = tmp->next;
  }
  prv->next = tmps->next;
  free(tmp);
  
  return sn;
}
// ================== REMOVE FXNS ==================




// ================== FREE   FXNS ==================
song_node * free_list( song_node *sn ) {

  song_node *f = sn;
  while ( sn ) {
    sn = sn->next;
    printf("freeing node: %s - %s\n", f->song, f->artist );
    free(f);
    f = sn;
  }

  return sn;
}
// ================== FREE   FXNS ==================
