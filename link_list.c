#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "link_list.h"

//STRING TO LOWERCASE (helper function) -done
char * str_tolower(char * str) {
  unsigned char *c = (unsigned char *)str;
  while(*c) {
    *c = tolower(*c);
    c++;
  }
  return str;
}

//INSERT AT FRONT -done
song_node * insert_front(song_node * head, char[] songName, char[]songArtist) {
  struct song_node * new_front = (struct song_node *)malloc(sizeof(struct song_node) );
  
  strcpy(new_front->name, str_tolower(songName) );
  strcpy(new_front->artist, str_tolower(songArtist) );
  new_front -> next = head;

  return song_node * new_front;
}

//INSERT IN ORDER -done
song_node * insert_order(song_node * head, char[] songName, char[] songArtist) {
    struct song_node * current = head;
    struct song_node * previous = NULL;

    if (strncmp(songName, head -> name, 256) < 0) {
      struct song_node * front = insert_front(head, songName, songArtist);
      return front;
    }
    while(head) {
      if (strncmp(songName, head -> name, 256) < 0) {
	struct song_node * new_here = insert_front(head, songName, songArtist);
	previous -> next = new_here;
	return current;
      }
      previous = head;
      head = head -> next;
    }
    
    struct song_node *  new_end= (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(new_end -> name, str_tolower(songName));
    strcpy(new_end -> artist, str_tolower(songArtist));
    
    previous -> next = new_end;
    return current;
}


//PRINT LIST -done
void print_list( song_node *head ) {
  song_node *current = head;
  
  while(current) {
    printf("\t %s - %s \n", current -> artist, current -> name);
    current = current -> next;
  } 
}


//FIND SONG -done
song_node * find_song(song_node * head, char[] songName) {
  struct song_node * front = head;
  
  if (strncmp(songName, head -> name, 256) == 0) { return head;} 
  while (head) {  
    if (strncmp(songName, head -> name, 256) == 0) {
      return head;
    }
    head = head -> next;
  }
  return front;
}


//FIND ARTIST -done
song_node * find_artist(song_node * head, char[] songArtist) {
  struct song_node * front = head;
  
  if (strncmp(songArtist, head -> artist, 256) == 0) { return head;} 
  while (head) {  
    if (strncmp(songArtist, head -> artist, 256) == 0) {
      return head;
    }
    head = head -> next;
  }
  return front;
}


//RANDOM ELEMENT -done
song_node * rand_element(song_node * head) {
  struct song_node * ret = head;
  int randNum = rand(time(null)) % len(tmp);
  
  while(randNum) {
    ret = ret -> next;
    randNum--;
  }
  return ret;
  
}


//REMOVE -done
song_node * remove(song_node * front, char [] songName) {
  if(!*front){
    return NULL;
  }else if(!strncmp(songName,front -> name,256)){
    song_node * newHead = front -> next;
    free(front);
    return newHead;
  }
  else{
    song_node prev = front;
    song_node current = front -> next;

    while(*current){
      if(!strncmp(current -> name,songName)){
	prev -> next = current -> next;
	free(current);
	return front;
      }
    } 
    return front;
  }
}


//FREE LIST -done
song_node * free_list(song_node *head) {
  song_node *current = head;
  
  while(head) {
    head = head->next;
    printf("freeing node: %s - %s\n", current->artist, current->song );
    free(current);
    current = head;
  }
  return head;
}
