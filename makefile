all: link_list.o playlist.o main.o
	gcc link_list.o playlist.o main.o -o run

list.o: link_list.c link_list.h
	gcc -c link_list.c

musicLib.o: playlist.c playlist.h
	gcc -c playlist.c

main.o: main.c
	gcc -c main.c

run: all
	./playlistOutput