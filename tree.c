/* Tree implementation
 * C file: tree.c: Function definiton
 * Author: Shantanu Jha
 * Version: 1.4
*/

#include "tree.h"
#include <assert.h>

N_ent* root_global = NULL;

int add_caller(int data) {
 	return add_node(data, &(root_global));
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

int add_node(int data, N_ent** node) {
	N_ent* new_node;
	new_node = (N_ent*) malloc (sizeof(N_ent));
	if (new_node == NULL)
	    return 0;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return addInternal(new_node, node);

}

int addInternal(N_ent* new_node, N_ent** node) { 
    	if (*node == NULL) {
     		(*node) = new_node;
     		return 1;
   	}	
   	if((*node)->data == new_node->data) {
     		free(new_node);
     		return 2;
   	}

   	else if((*node)->data > new_node->data) {
    		return addInternal(new_node, &(*node)->left);
   	}
   	else if((*node)->data < new_node->data) {
    		return addInternal(new_node, &(*node)->right);
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

