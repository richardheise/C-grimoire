
typedef struct t_item t_item;

struct t_node {
    int key;
    struct t_node *next; 
};
typedef struct t_node t_node;

struct t_list {
    t_node *start;
    int size;
};
typedef struct t_list t_list;

int create_list(t_list *l);
int is_list_empty(t_list *l);
void destroy_list(t_list *l);
int insert_at_beginning(int x, t_list *l);
int insert_at_end(int x, t_list *l);
int insert_in_order(int x, t_list *l);
void print_list(t_list *l);
int remove_first(int *item, t_list *l);
int remove_last(int *item, t_list *l);
int remove_item(int key, int *item, t_list *l);
int belongs_to_list(int key, t_list *l);
int concatenate_lists(t_list *l, t_list *m);
int copy_list(t_list *l, t_list *m);
