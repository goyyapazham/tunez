#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "playlist.h"

int main() {

  //1 spiffy playlist coming right up...
  printf("\n----------- TESTING ADD_SONG -----------\n");
  add_song("formation", "beyonce");
  add_song("wow", "beck");
  add_song("hey ya", "outkast");
  add_song("lowkey", "tweedy");
  add_song("dreams", "fleetwood mac");
  add_song("no scrubs", "tlc");
  add_song("rhiannon", "fleetwood mac");
  add_song("sorry", "beyonce");
  add_song("believe", "ozomatli");
  add_song("if i were a boy", "beyonce");
  add_song("dreams", "beck");
  printf("\n");
  print_library();
  printf("\n");

  //put the playlist to the test: is it /really/ spiffy?
  printf("\n----------- TESTING FIND_SONG -----------\n");
  find_song("rhiannon");
  find_song("if i were a boy");
  find_song("freedom");
  printf("\n----------- TESTING FIND_ARTIST -----------\n");
  find_artist("beyonce");
  find_artist("outkast");
  find_artist("the beatles");
  printf("\n");

  //testing print fxns
  printf("----------- TESTING PRINT_ARTIST -----------\n");
  print_artist("beyonce");
  print_artist("outkast");
  print_artist("the beatles");
  
}
