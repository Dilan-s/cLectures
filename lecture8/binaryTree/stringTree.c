#include <string.h>    
#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"

int string_compare(void *val1, void *val2) {
  return strcmp((const char *) val1, (const char *) val2); //return -1 if val1 < val2, 0 if val1 == val2, 1 if val1 > val2
}

int main(){
  bst tree;
  bst_init(&tree, string_compare);
  
  char s1[] = "Bob";
  bst_insert(&tree, s1);

  char s2[] = "Alice";
  bst_insert(&tree, s2);
  
  char s3[] = "Eve";
  bst_insert(&tree, s3);

  bst_for_each(&tree, bst_print_string);

  //bst_for_each(&tree, &free); if values were allocated on the heap
  bst_destroy(&tree);

  //-------------------------------------

  bst_init(&tree, &string_compare);

  FILE *out = fopen("output.txt", "w");
  if (out == NULL) {
    perror("opening File");
    return EXIT_FAILURE;
  }
  print_state context;
  context.file = out;

  bst_insert(&tree, s1);
  bst_insert(&tree, s2);
  bst_insert(&tree, s3);
  
  bst_for_each_context(&tree, &bst_print_string_context, &context);

  fclose(out);

  //  bst_for_each(&tree, &free);
  bst_destroy(&tree);
  
  return EXIT_SUCCESS;
}
