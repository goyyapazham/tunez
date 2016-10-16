#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "songz.h"

int main() {

  //INITIALIZE LISTS FOR TESTING
  song_node *list = 0;
  song_node *artist_search = 0;
  song_node *song_search = 0;
  song_node *rand_search = 0;

  //INITIALIZE PSEUDO-RANDOM NUMBER GENERATOR
  srand(time(NULL));

  //TESTING INSERT_ORDERED
  printf("----------- TESTING INSERT_ORDERED -----------\n");

  printf("ADDING BEYONCE - FORMATION...\n");
  list = insert_ordered(list, "formation", "beyonce");
  
  printf("ADDING OUTKAST - HEY YA...\n");
  list = insert_ordered(list, "hey ya", "outkast");
  
  printf("ADDING BEYONCE - FREEDOM...\n");
  list = insert_ordered(list, "freedom", "beyonce");

  printf("ADDING MANU CHAO - CLANDESTINO...\n");
  list = insert_ordered(list, "clandestino", "manu chao");
  
  printf("ADDING BECK - WOW...\n");
  list = insert_ordered(list, "wow", "beck");

  printf("ADDING ZEBDA - TOUT SEMBLE SI...\n");
  list = insert_ordered(list, "tout semble si", "zebda");

  printf("ADDING ABBA - FERNANDO...\n");
  list = insert_ordered(list, "fernando", "abba");

  printf("ADDING ABBA - SOS...\n");
  list = insert_ordered(list, "sos", "abba");

  printf("ADDING NINA SIMONE - SINNERMAN...\n\n");
  list = insert_ordered(list, "sinnerman", "nina simone");
  print_list(list);

  /*
  //TESTING FIND_ARTIST
  printf("\n----------- TESTING FIND_ARTIST -----------\n");

  printf("\nSEARCHING FOR ABBA...\n");
  artist_search = find_artist(list, "abba");
  print_list(artist_search);
  
  printf("SEARCHING FOR NINA SIMONE...\n");
  artist_search = find_artist(list, "nina simone");
  print_list(artist_search);

  printf("\nSEARCHING FOR RIHANNA...\n");
  artist_search = find_artist(list, "rihanna");
  print_list(artist_search);

  printf("\nSEARCHING FOR BEYONCE...\n");
  artist_search = find_artist(list, "beyonce");
  print_list(artist_search);

  //TESTING FIND_SONG
  printf("\n----------- TESTING FIND_SONG -----------\n");

  printf("SEARCHING FOR FORMATION...\n");
  song_search = find_song(list, "formation");
  print_list(song_search);
  
  printf("\nSEARCHING FOR CLANDESTINO...\n");
  song_search = find_song(list, "clandestino");
  print_list(song_search);

  printf("\nSEARCHING FOR HEY JUDE...\n");
  song_search = find_song(list, "hey jude");
  print_list(song_search);

  printf("\nSEARCHING FOR HEY YA...\n");
  song_search = find_song(list, "hey ya");
  print_list(song_search);

  //TESTING FIND_RANDOM
  printf("\n----------- TESTING FIND_RANDOM -----------\n");

  printf("SEARCHING FOR RANDOM...\n");
  rand_search = find_random(list);
  print_list(rand_search);
  
  printf("\nSEARCHING FOR RANDOM...\n");
  rand_search = find_random(list);
  print_list(rand_search);
  
  printf("\nSEARCHING FOR RANDOM...\n");
  rand_search = find_random(list);
  print_list(rand_search);
  
  printf("\nSEARCHING FOR RANDOM...\n");
  rand_search = find_random(list);
  print_list(rand_search);
  */

  //TESTING REMOVE_SONG
  printf("\n----------- TESTING REMOVE_SONG -----------\n");

  printf("REMOVING ABBA - SOS...\n");
  list = remove_song(list, "sos", "abba");
  print_list(list);

  printf("\nREMOVING MANU CHAO - CLANDESTINO...\n");
  list = remove_song(list, "clandestino", "manu chao");
  print_list(list);

  printf("\nREMOVING ADELE - HELLO...\n");
  list = remove_song(list, "hello", "adele");
  print_list(list);

  printf("\nREMOVING ABBA - DANCING QUEEN...\n");
  list = remove_song(list, "dancing queen", "abba");
  print_list(list);

  printf("\nREMOVING PHARRELL - FREEDOM...\n");
  list = remove_song(list, "freedom", "pharrell");
  print_list(list);
  
  return 0;
}
