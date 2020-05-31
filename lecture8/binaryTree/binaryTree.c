#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

bst_elem *bst_alloc_elem(void) {
  bst_elem *elem = malloc(sizeof(bst_elem));
  if (elem == NULL) {
    perror("bst_alloc_elem");
    exit(EXIT_FAILURE);
  }
  return elem;
}

void bst_free_elem(bst_elem *elem) {
  free (elem);
}

void bst_init(bst *handle, bst_compare_t compare) {
  handle->compare = compare;
  handle->tree = NULL;
}

static bst_elem *bst_insert_elem(bst_elem *const elem, bst_compare_t compare, void *value){
  if (elem == NULL) {
    bst_elem *new_elem = bst_alloc_elem();
    new_elem->left = new_elem->right = NULL;
    new_elem->value = value;
    return new_elem;
  } else {
    const int comparison = compare (value, elem->value);
    if (comparison < 0) {
      elem->left = bst_insert_elem(elem->left, compare, value);
    } else if (comparison > 0){
      elem->right = bst_insert_elem(elem->right, compare, value);
    }
    return elem;
  }
}

void bst_insert(bst *handle, void *value) {
  handle->tree = bst_insert_elem(handle->tree, handle->compare, value);
}

void bst_for_each_elem(bst_elem *elem, void (*func)(void *)) {
  if (elem == NULL) {
    return;
  }
  bst_for_each_elem(elem->left, func);
  func(elem->value);
  bst_for_each_elem(elem->right, func);
}
  
void bst_for_each(bst *handle, void (*func)(void *)){
  bst_for_each_elem(handle->tree, func);
}

void bst_print_string(void *value) {
  const char *str = (const char *) value;
  printf("%s\n", str);
}

static void bst_destroy_elem(bst_elem *elem) {
  if (elem == NULL) {
    return;
  }
  bst_destroy_elem(elem->left);
  bst_destroy_elem(elem->right);
  bst_free_elem(elem);
}
 
void bst_destroy(bst *handle) {
  bst_destroy_elem(handle->tree);
}

void bst_print_string_context(void *context, void *value) {
  print_state *state = (print_state *) context;
  const char *str = (const char *) value;
  fprintf(state->file, "%s\n", str);
}

static void bst_for_each_elem_context (bst_elem *elem, void (*func)(void *, void *), void *context) {

  if (elem == NULL) {
    return;
  }

  bst_for_each_elem_context(elem->left, func, context);
  func(context, elem->value);
  bst_for_each_elem_context(elem->right, func, context);
}

void bst_for_each_context(bst *handle, void (*func)(void *, void *), void *context) {
  bst_for_each_elem_context(handle->tree, func, context);
}
