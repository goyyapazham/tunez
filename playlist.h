// ================== ADD    FXNS ==================
//add song to library in correct order
void add_song( char song[], char artist[] ); //DONE

// ================== SEARCH FXNS ==================
//return ptr to specified song
void find_song(char song[]); //DONE
//return ptr to first song by specified artist
void find_artist(char artist[]); //wrapper, done
void find_a(char artist[], char filler[]); //to avoid redundancy w/ print_artist, DONE

// ================== PRINT  FXNS ==================
//print all entries under a certain letter
void print_letter( char letter ); //DONE
//print all entries from a certain artist
void print_artist( char artist[] ); //DONE
//print entire library
void print_library(); //DONE
//print shuffled library
void shuffle();

// ================== DELETE FXNS ==================
//delete specified song
void delete_song( char song[], char artist[] ); //DONE
//delete entire library
void delete_library(); //DONE
