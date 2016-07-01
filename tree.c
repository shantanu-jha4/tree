/* Tree implementation
 * C file: tree.c: Function definiton
 * Author: Shantanu Jha
 * Version: 1.2
*/

#include "tree.h"
#include <assert.h>

N_ent* root_global = NULL;
int is_root_null = 0;

int add_caller(int data) {
 	return add_node(data, root_global);
}

void print_root() {
 	printf("Root: %d\n", root_global->data);
}

N_ent* create_node(int data) {
  N_ent* temp = (N_ent*) malloc (sizeof(N_ent));
  if (temp == NULL)
      return NULL;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

int add_node(int data, N_ent* node) {
	N_ent* new_node;
	new_node = (N_ent*) malloc (sizeof(N_ent));
	if (new_node == NULL)
	    return 0;
	new_node->data = data;
	//if (node)
	 // printf("New Node: %d, Node: %d\n", new_node->data, node->data);
	//printf("New Node: %d\n", new_node->data);
	return addInternal(new_node, node);
}

int addInternal(N_ent* new_node, N_ent* node) {
  
    printf(" %p\n", (void*)node);
    if (node == NULL) {
     //assert(node == root_global);
     //root_global = (N_ent*) malloc (sizeof(N_ent));
     //node = new_node;
     //assert (node->right == NULL);
     //assert (node->left == NULL);
     if (is_root_null == 0) {
     	printf("Root time: \n");
	is_root_null = 1;
	root_global = new_node;
	root_global->left = NULL;
	root_global->right = NULL;
	printf("Root Address: %p\n", (void*)root_global);
	return 1;
     }
     node = (N_ent*) malloc (sizeof(N_ent));
     if (node == NULL)
	 return 0;
     node->data = new_node->data;
     node = new_node;
    // printf("%p, %p\n", (void*)node, (void*)root_global);
     //printf("Added: %d\n", node->data);
     //printf("%d\n", root_global->data);
     node->left = NULL;
     node->right = NULL;
     assert (node->right == NULL);
     assert (node->left == NULL);
     return 1;
   }
   //printf ("%d, %d\n" ,node->data, new_node->data);
   if(node->data == new_node->data) {
     free(new_node);
     return 2;
   }

   else if(node->data > new_node->data) {
     //printf("Left..\n");
     assert(node->left == NULL);
     return addInternal(new_node, node->left);
   }
   else if(node->data < new_node->data) {
     //printf("Right\n");
     assert(node->right == NULL);

     /*if (node->right)
	 printf("Transfer: %d\n", node->right->data);*/
     return addInternal(new_node, node->right);
   }

   else
     return 0;
}

N_ent* search_caller(N_ent* to_search) {
  return search(to_search, root_global);
}

N_ent* search(N_ent* to_search, N_ent* node) { 
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

