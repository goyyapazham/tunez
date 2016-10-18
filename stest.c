#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "songlist.h"

int main() {

  //INITIALIZE PSEUDO-RANDOM NUMBER GENERATOR
  srand(time(NULL));

  //INITIALIZE LISTS FOR TESTING
  song_node *list = 0;
  song_node *artist_search = 0;
  song_node *song_search = 0;
  song_node *rand_search = 0;

  //TESTING INSERT
  printf("--------------- TESTING INSERT ---------------\n");

  printf("adding beyonce - formation...\n");
  list = insert(list, "formation", "beyonce");
  
  printf("adding outkast - hey ya...\n");
  list = insert(list, "hey ya", "outkast");
  
  printf("adding beyonce - freedom...\n");
  list = insert(list, "freedom", "beyonce");

  printf("adding manu chao - clandestino...\n");
  list = insert(list, "clandestino", "manu chao");
  
  printf("adding beck - wow...\n");
  list = insert(list, "wow", "beck");

  printf("adding zebda - tout semble si...\n");
  list = insert(list, "tout semble si", "zebda");

  printf("adding abba - fernando...\n");
  list = insert(list, "fernando", "abba");

  printf("adding abba - sos...\n");
  list = insert(list, "sos", "abba");

  printf("adding nina simone - sinnerman...\n");
  list = insert(list, "sinnerman", "nina simone");
  
  print(list);

  //TESTING FIND_ARTIST
  printf("\n----------- TESTING FIND_ARTIST -----------");

  printf("\nsearching for abba...");
  artist_search = find_Artist(list, "abba");
  print(artist_search);
  
  printf("\nsearching for nina simone...");
  artist_search = find_Artist(list, "nina simone");
  print(artist_search);

  printf("\nsearching for rihanna...");
  artist_search = find_Artist(list, "rihanna");
  print(artist_search);

  printf("\nsearching for beyonce...");
  artist_search = find_Artist(list, "beyonce");
  print(artist_search);

  //TESTING FIND_SONG
  printf("\n----------- TESTING FIND_SONG -----------\n");

  char err[] = "\nSong not found.";

  printf("searching for formation...");
  song_search = find_Song(list, "formation", err);
  print(song_search);
  
  printf("\nsearching for clandestino...");
  song_search = find_Song(list, "clandestino", err);
  print(song_search);

  printf("\nsearching for hey jude...");
  song_search = find_Song(list, "hey jude", err);
  print(song_search);

  printf("\nsearching for hey ya...");
  song_search = find_Song(list, "hey ya", err);
  print(song_search);

  //TESTING FIND_RANDOM
  printf("\n----------- TESTING FIND_RANDOM -----------\n");

  printf("searching for random...");
  rand_search = find_random(list);
  print(rand_search);
  
  printf("\nsearching for random...");
  rand_search = find_random(list);
  print(rand_search);
  
  printf("\nsearching for random...");
  rand_search = find_random(list);
  print(rand_search);
  
  printf("\nsearching for random...");
  rand_search = find_random(list);
  print(rand_search);

  //TESTING REMOVE_SONG
  printf("\n----------- TESTING REMOVE_SONG -----------\n");

  printf("removing abba - fernando...");
  list = remove_song(list, "fernando", "abba");
  print(list);

  printf("\nremoving manu chao - clandestino...");
  list = remove_song(list, "clandestino", "manu chao");
  print(list);

  printf("\nremoving zebda - tout semble si...");
  list = remove_song(list, "tout semble si", "zebda");
  print(list);

  printf("\nremoving adele - hello...");
  list = remove_song(list, "hello", "adele");
  print(list);
  
  //TESTING FREE_LIST
  printf("\n------------- TESTING  FREE_LIST -------------");
  print(list);
  printf("\n");
  list = free_list(list);
  print(list);
}
