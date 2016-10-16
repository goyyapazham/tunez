typedef struct song_node {
  char song[256];
  char artist[256];
  struct song_node *next;
} song_node;

// ================== INSERT FXNS ==================
//insert new song to front of list, return ptr to front of list
song_node * insert_front(song_node *list, char song[], char artist[]);
//insert new song to list alphabetically, return ptr to front of list
song_node * insert(song_node *list, char song[], char artist[]); //wrapper fxn
song_node * insert_ordered(song_node *list, char song[], char artist[]);

// ================== PRINT  FXNS ==================
//print entire list
void print_list(song_node *list);

// ================== SEARCH FXNS ==================
//search list, & return ptr to, specified song
song_node * find_Song(song_node *list, char song[]);
//search list, & return ptr to, first song by specified artist
song_node * find_Artist(song_node *list, char artist[]);
//return ptr to random song in list
song_node * find_random(song_node *list);

// ================== REMOVE FXNS ==================
//remove specified song from list, return ptr to front of list
song_node * remove_song(song_node *list, char song[], char artist[]);

// ================== FREE   FXNS ==================
//free entire list
song_node * free_list(song_node *list);
