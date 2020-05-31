#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "orderedListInts.h"


// this function returns a pointer to a newly created node
// note that we set the pointer to the next node to NULL
static Node *create_new_node(const int value) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("Unable to allocate memory");
    return EXIT_FAILURE;
  }
  new_node->contents = value;
  new_node->next = NULL;
  return new_node;
}

// set up an empty list
void initialise_list(List *l) {
  if (l == NULL){
    printf("List is NULL");
    return EXIT_FAILURE;
  }
  l->front = l->rear = NULL; 
}

// add a node to the front of the list
static void add_to_front(List *l, const int value) {
  Node *item = create_new_node(value);
  
  // empty list case
  if (!l->front) {
    l->front = l->rear = item;
    return;
  }

  // default case
  item->next = l->front;
  l->front = item;
}

// add a node to the rear of the list
void add_to_rear(List *l, const int value) {
  Node *item = create_new_node(value);
  
  // empty list case
  if (!l->front) {
    l->front = l->rear = item;
    return;
  }

  // default case
  (l->rear)->next = item;
  l->rear = item;
}

// output the list to the screen
void print_list(const List *l) {
  for (const Node *current = l->front; current; current=current->next) 
    printf("[%d] ", current->contents);
  printf("\n");
}

// insert a word into a sorted list
void add(List *l, const int new_value) {
  Node *p = l->front, *q = NULL;

  // find the node we want to insert after
  for (p=l->front; p && p->contents < new_value; p=p->next) 
    q = p;

  // p points to the node we want to insert before
  // q points to the node we want to insert after

  if (q==NULL) {
    add_to_front(l, new_value);
    return;
  }

  if (p==NULL) {
    add_to_rear(l, new_value);
    return;
  }

  if (p->contents == new_value){
    return;
  }

  // otherwise create the new node 
  Node *new_node = create_new_node(new_value);

  // and insert it after q and before p
  new_node->next = p;
  q->next = new_node;
}

// delete all items in the list
void free_list(List *l) {
  // keep deleting items from the front of the list until there is nothing left
  while (l->front != NULL) {
    Node *link = (l->front)->next;
    free(l->front);
    l->front = link;
  }
  l->rear = NULL;
}
