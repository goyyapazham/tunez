#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "playlist.h"

int main() {

  srand(time(NULL));

  //TESTING ADD_SONG
  printf("----------- TESTING ADD_SONG -----------\n");
  add_song("formation", "beyonce");
  add_song("wow", "beck");
  add_song("hey ya", "outkast");
  add_song("lowkey", "tweedy");
  add_song("gypsy", "fleetwood mac");
  add_song("no scrubs", "tlc");
  add_song("rhiannon", "fleetwood mac");
  add_song("sorry", "beyonce");
  add_song("believe", "ozomatli");
  add_song("if i were a boy", "beyonce");
  add_song("dreams", "beck");
  print_library();
  printf("\n");

  /*
  //TESTING FIND FXNS
  printf("----------- TESTING FIND_SONG -----------\n");
  printf("looking for rhiannon...");
  find_song("rhiannon");
  printf("\nlooking for if i were a boy...");
  find_song("if i were a boy");
  printf("\nlooking for freedom...");
  find_song("freedom");
  printf("\n----------- TESTING FIND_ARTIST -----------\n");
  printf("looking for beyonce...");
  find_artist("beyonce");
  printf("\nlooking for outkast...");
  find_artist("outkast");
  printf("\nlooking for the beatles...");
  find_artist("the beatles");
  */
    
  //TESTING PRINT FXNS
  printf("\n----------- TESTING PRINT_LETTER -----------\n");
  print_letter('b');
  print_letter('o');
  print_letter('s');
  print_letter('t');
  print_letter('y');
  printf("----------- TESTING PRINT_ARTIST -----------\n");
  print_artist("beyonce");
  print_artist("outkast");
  print_artist("the beatles");
  printf("\n----------- TESTING SHUFFLE -----------\n");
  shuffle();
  shuffle();
  shuffle();

  //TESTING DELETE FXNS
  printf("----------- TESTING DELETE_SONG -----------");
  print_library();
  delete_song("sorry", "beyonce");
  delete_song("dreams", "beck");
  delete_song("hello", "adele");
  printf("\n");
  printf("\n----------- TESTING DELETE_LIBRARY -----------");
  print_library();
  printf("\n\n");
  delete_library();
  print_library();
  printf("\n");
}
