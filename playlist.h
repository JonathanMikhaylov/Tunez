//Jonathan Mikhaylov period 10

song_node * table[26];

void add_song(song_node *[], char [], char []);
struct song_node * search_song(song_node *[], char [], char []);
struct song_node * search_artist(song_node *[], char []);
void print_letter(song_node *[], char);
void print_artist(song_node *[], char []);
void print_library(song_node *[]);
void shuffle(song_node *[], int);
struct song_node * delete_song(song_node *[], char [], char []);
void delete(song_node *[]);
