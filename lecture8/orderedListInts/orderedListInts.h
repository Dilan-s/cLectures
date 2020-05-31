typedef struct Node {
  int contents;
  struct Node *next; //pointer to the next node
} Node;

typedef struct Node Node;

typedef struct List {
  Node *front;
  Node *rear;
} List;

void add(List *l, const int new_value);

void free_list(List *l);

void initialise_list(List *l);

