/* Tree implementation
 * C file: tree.c: Function definiton
 * Author: Shantanu Jha
 * Version: 1.1
*/

#include "tree.h"

N_ent* root_global = NULL;

/*T_ent* create_tree() {
   T_ent* tree_list = (T_ent*) malloc (sizeof(T_ent));
   if (tree_list == NULL)
       return NULL;
   tree_list->root = NULL;
   return tree_list; 
}
*/

int add_caller(int data) {
  return add_node(data, root_global);
}

int add_node(int data, N_ent* node) {
	N_ent* new_node;
	new_node = (N_ent*) malloc (sizeof(N_ent));
	if (new_node == NULL)
	    return 0;
	new_node->data = data;
	return addInternal(new_node, root_global);
}

int addInternal(N_ent* new_node, N_ent* node) {
   if (node == NULL) {
     node = new_node;
     return 1;
   }
   if(node->data == new_node->data) {
     free(new_node);
     return 2;
   }

   else if(node->data > new_node->data) {
     return addInternal(new_node, node->left);
   }
   else if(node->data < new_node->data) {
     return addInternal(new_node, node->right);
   }

   else
     return 0;
}

N_ent* search(N_ent* to_search, N_ent* node) { 
    node = root_global;
    if (node == NULL)
	return NULL;
    if (to_search->data == node->data)
	return node;
    else if (node->data > to_search->data)
	return search(to_search, node->left);       
   else if(node->data < to_search->data)
        return search(to_search, node->right);
   else
       return NULL;
}

