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
song_node * insert_ordered( song_node *sn, char s[], char a[] ) {

  song_node *tmp = sn;

  //CASE #1: list is empty
  if( !tmp )
    return insert_front(sn, s, a);

  //CASE #2: recursively reached first existing artist ahead of me in ABC order
  if( strcmp(a, tmp->artist) < 0 )
    return insert_front(tmp, s, a);

  //CASE #3: recursively reached my artist, first existing song ahead of me in ABC order
  if( strcmp(a, tmp->artist) == 0 && strcmp(s, tmp->song) < 0 )
    return insert_front(tmp, s, a);

  //RECURSIVE CALL: call fxn on next node
  else
    tmp->next = insert_ordered(tmp->next, s, a);

  return sn;
}
// ================== INSERT FXNS ==================

// ================== PRINT  FXNS ==================
void print_list( song_node *sn ) {
  
  while(sn) {
    printf("%s - %s\n", sn->artist, sn->song);
    sn = sn->next;
  }
  
}
// ================== PRINT  FXNS ==================

// ================== SEARCH FXNS ==================
//search list, & return ptr to, first song w/ specified name
song_node * find_song(song_node *sn, char s[]) {
  
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
    return find_song(tmp->next, s);

  //if not found
  return 0;
}

//search list, & return ptr to, first song by specified artist
song_node * find_artist(song_node *sn, char a[]) {

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
    return find_artist(tmp->next, a);

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
  song_node *tmpa = find_artist(tmp, a);
  song_node *tmps = find_song(tmpa, s);

  if( !tmp || !tmps || tmp == tmps )
    return tmp;

  while(tmp) {
    if( tmp == tmps ) {
      *tmp = *(tmps->next);
      return sn;
    }
    tmp = tmp->next;
  }

  return 0;
  
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