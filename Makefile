all: tree_run

tree_run: tree.c main.c tree.h
	gcc -Werror -Wall -g -o tree_run main.c tree.c
