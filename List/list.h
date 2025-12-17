// GRR20191053 Richard Fernando Heise Ferreira 
// Definição e operações em uma lista genérica.

#ifndef __LIST__
#define __LIST__

#ifndef NULL
#define NULL ((void *) 0)
#endif

//------------------------------------------------------------------------------
// estrutura de uma lista genérica, sem conteúdo definido.
// Veja um exemplo de uso desta estrutura em testalista.c

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

//------------------------------------------------------------------------------
// Cria uma lista vazia.
// Retorno: 1 se sucesso, 0 se falha.
int create_list(t_list *l);

//------------------------------------------------------------------------------
// Verifica se a lista está vazia.
// Retorno: 1 se vazia, 0 se não.
int is_list_empty(t_list *l);

//------------------------------------------------------------------------------
// Destroi a lista, liberando a memória.
void destroy_list(t_list *l);

//------------------------------------------------------------------------------
// Insere um elemento no início da lista.
// Retorno: 1 se sucesso, 0 se falha.
int insert_at_beginning(int x, t_list *l);

//------------------------------------------------------------------------------
// Insere um elemento no final da lista.
// Retorno: 1 se sucesso, 0 se falha.
int insert_at_end(int x, t_list *l);

//------------------------------------------------------------------------------
// Insere um elemento em ordem na lista.
// Retorno: 1 se sucesso, 0 se falha.
int insert_in_order(int x, t_list *l);

//------------------------------------------------------------------------------
// Imprime o conteúdo da lista.
void print_list(t_list *l);

//------------------------------------------------------------------------------
// Remove o primeiro elemento da lista.
// Retorno: 1 se sucesso, 0 se falha.
int remove_first(int *item, t_list *l);

//------------------------------------------------------------------------------
// Remove o último elemento da lista.
// Retorno: 1 se sucesso, 0 se falha.
int remove_last(int *item, t_list *l);

//------------------------------------------------------------------------------
// Remove um elemento específico da lista.
// Retorno: 1 se sucesso, 0 se falha.
int remove_item(int key, int *item, t_list *l);

//------------------------------------------------------------------------------
// Verifica se um elemento pertence à lista.
// Retorno: 1 se pertence, 0 se não.
int belongs_to_list(int key, t_list *l);

//------------------------------------------------------------------------------
// Concatena duas listas.
// Retorno: 1 se sucesso, 0 se falha.
int concatenate_lists(t_list *l, t_list *m);

//------------------------------------------------------------------------------
// Copia uma lista para outra.
// Retorno: 1 se sucesso, 0 se falha.
int copy_list(t_list *l, t_list *m);

#endif
