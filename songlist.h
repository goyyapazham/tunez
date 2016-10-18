typedef struct song_node {
  char song[256];
  char artist[256];
  struct song_node *next;
} song_node;

// ================== INSERT FXNS ==================
//insert new song to front of list, return ptr to front of list
song_node * insert_front(song_node *list, char song[], char artist[]);//DONE
//insert new song to list alphabetically, return ptr to front of list
song_node * insert(song_node *list, char song[], char artist[]); //wrapper fxn, DONE
song_node * insert_ordered(song_node *list, char song[], char artist[]);//DONE

// ================== PRINT  FXNS ==================
//print entire list
void print(song_node *list);//wrapper fxn, DONE
void print_list(song_node *list);//DONE

// ================== SEARCH FXNS ==================
//search list, & return ptr to, specified song
song_node * find_Song(song_node *list, char song[], char err[]);//DONE
//search list, & return ptr to, first song by specified artist
song_node * find_Artist(song_node *list, char artist[]);//DONE
//return ptr to random song in list
int len(song_node *list); //helper fxn for find_random
song_node * find_random(song_node *list);//DONE

// ================== REMOVE FXNS ==================
//remove specified song from list, return ptr to front of list
song_node * remove_song(song_node *list, char song[], char artist[]);//DONE

// ================== FREE   FXNS ==================
//free entire list
song_node * free_list(song_node *list);//DONE
