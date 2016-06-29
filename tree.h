/* Tree implementation
 * Header file: tree.h: Structure declaration and required functions
 * Author: Shantanu Jha
 * Version: 1.1
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of Tree entity
typedef struct _t_ent {
   int data;
   struct _t_ent* left;
   struct _t_ent* right;
 } N_ent;

/*typedef struct _root_ent {
  N_ent* root; // its the root element
} T_ent; */

// Functions (declaration only) 

//T_ent* create_tree();

int add_caller(int data);

int addInternal(N_ent* new_node, N_ent* node);

int add_node(int data, N_ent* node);

N_ent* search(N_ent* to_search, N_ent* node);


