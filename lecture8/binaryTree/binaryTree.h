typedef int (*bst_compare_t)(void *val1, void *val2);

struct bst_elem;

typedef struct bst {
  bst_compare_t compare;
  struct bst_elem *tree;
} bst;

typedef struct bst_elem {
  struct bst_elem *left;
  struct bst_elem *right;
  void *value;
} bst_elem;

typedef struct print_state {
  FILE *file;
} print_state;

bst_elem *bst_alloc_elem(void);

void bst_free_elem(bst_elem *elem);

void bst_init(bst *handle, bst_compare_t compare);

void bst_insert(bst *handle, void *value);

void bst_for_each(bst *handle, void (*func)(void *));

void bst_print_string(void *value);

void bst_destroy(bst *handle);

void bst_print_string_context(void *context, void *value);

void bst_for_each_context(bst *handle, void (*func)(void *, void *), void *context);
