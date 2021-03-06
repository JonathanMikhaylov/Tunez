#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "link_list.h"
#include "playlist.h"

int find_place(char i){
  return i-97;
}

//ADD SONG -done
void add_song(song_node * arr[], char songNames[], char songArtists[]) {
  char front_letter = songArtists[0];
  int place = find_place(front_letter);

  printf("Adding %s by %s\n", songNames, songArtists);
  arr[place] = insert_order(table[place], songNames, songArtists);
}

//SEARCH SONG
song_node * search_song(song_node *arr[], char songNames[], char songArtists[]){
  return (find_song (arr[ (find_place(songArtists[0]) )], songNames));
}


//SEARCH ARTIST
song_node * search_artist(song_node *arr[], char songArtists[]){
  return (find_artist (arr[ (find_place(songArtists[0])) ], songArtists));
}


//PRINT LETTER

//PRINT ARTIST

//PRINT LIBRARY

//SHUFFLE

//DELETE SONG

//DELETE
