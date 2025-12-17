#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int create_list(t_list *l) {
    l->start = NULL;
    l->size = 0;
    return 1;
}

int is_list_empty(t_list *l) {
    if (l->start == NULL || l->size == 0)
        return 1;
    return 0;
}

/* um ponteiro auxiliar destroi a proxima posição */
/* enquanto o inicio percorre a lista. Custo linear */
void destroy_list(t_list *l) {
    if (! is_list_empty(l)) {
        t_node *aux_ptr = malloc(sizeof(t_node));
        if (aux_ptr == NULL) {
            printf("Falha de memória. Abortando.\n");
            return;
        }
        while (l->start != NULL) {
            aux_ptr->next = l->start;
            l->start = l->start->next;
            free(aux_ptr->next); 
            aux_ptr->next = NULL;
        }
        free(aux_ptr);
        l->size = 0;
    }
    printf("Não destruida: lista vazia\n");
}

/* um ponteiro auxiliar aponta para a primeira posição */
/* o inicio passa a apontar para o auxiliar */
int insert_at_beginning(int x, t_list *l) {
    t_node *aux_ptr = malloc(sizeof(struct t_node));
    if (aux_ptr == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    aux_ptr->key = x;
    aux_ptr->next = l->start;
    l->start = aux_ptr;
    l->size++;
    return 1; 
}

/* percorre a lista, usando um auxiliar, até achar o fim */
/* o fim passa a apontar para o auxiliar e este recebe null */
int insert_at_end(int x, t_list *l) {
    if (l->start == NULL) {
        insert_at_beginning(x, l);
        return 1;
    }
    t_node *aux_ptr = malloc(sizeof(struct t_node));
    if (aux_ptr == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    aux_ptr->key = x;
    aux_ptr->next = l->start;
    while (aux_ptr->next->next != NULL) {
        aux_ptr->next = aux_ptr->next->next;
    }
    aux_ptr->key = x;
    aux_ptr->next->next = aux_ptr;
    aux_ptr->next = NULL;
    l->size++;
    return 1;
}

/* insere um elemento na posição correta */
int insert_in_order(int x, t_list *l) {
    /* se a lista é vazia o elemento é inserido no inicio */
    if (is_list_empty(l)) {
        insert_at_beginning(x, l);
        return 1;
    }
    /* se a primeira posição é menor que o elemento */
    /* o elemento é inserido no início */
    if (x <= l->start->key) {
        insert_at_beginning(x, l);
        return 1;
    } 
    /* acabamos de garantir que o tamanho da lista é maior que 2 */
    t_node *aux_ptr = malloc (sizeof(t_node));
    if (aux_ptr == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    aux_ptr->next = l->start;

    /* enquanto não estivermos na última posição */
    while (aux_ptr->next->next != NULL) {
        /* verificamos se o x se encaixa */
        /* com nosso auxiliar apontado para o um nodo antes */
        /* da posição maior que x, ou seja, se y < x < w */
        /* estamos apontando para o nodo de chave y */
        if (x >= aux_ptr->next->key && x <= aux_ptr->next->next->key) {
            t_node *temp_ptr = malloc (sizeof(t_node));
            if (temp_ptr == NULL) {
                printf("Falha de memória. Abortando.\n");
                return 0;
            }
            temp_ptr->next = aux_ptr->next;
            aux_ptr->next = aux_ptr->next->next;
            aux_ptr->key = x;
            temp_ptr->next->next = aux_ptr;
            l->size++;
            free(temp_ptr);
            return 1;
        }
        /* andamos na lista se ainda não achamos o lugar de x */
        aux_ptr->next = aux_ptr->next->next;
    }
    /* andamos até a última posição e não achamos o lugar de x; */
    /* comparamos, então, com o último elemento */
    if (x > aux_ptr->next->key) {
        free(aux_ptr);
        insert_at_end(x, l);
        return 1;
    }
    return 0;
}   

/* imprimimos elementos até a última a posição */
void print_list(t_list *l) {
    if (! is_list_empty(l)) {
        t_node *aux_ptr = malloc(sizeof(t_node));
        if (aux_ptr == NULL) {
            printf("Falha de memória. Abortando.\n\n");
            return;
        } 
        aux_ptr->next = l->start;
        while (aux_ptr->next != NULL) {
            printf("%d ", aux_ptr->next->key);
            aux_ptr->next = aux_ptr->next->next;
        }
        free(aux_ptr);
        printf("\n");
    }
}

/* se a lista não é vazia vamos fazer o inicio */
/* apontar para o próximo nodo e liberar o antigo primeiro nodo*/
int remove_first(int *item, t_list *l) {
    if (l->start != NULL) {
        t_node *aux_ptr = malloc(sizeof(t_node));
        if (aux_ptr == NULL) {
            printf("Falha de memória. Abortando.\n\n");
            return 0;
        }
        aux_ptr->next = l->start;
        l->start = l->start->next;
        *item = aux_ptr->next->key;
        free(aux_ptr->next);
        free(aux_ptr);
        l->size--;
        return 1;
    }
    return 0;
}

/* andamos até o último nodo e o removemos */
int remove_last(int *item, t_list *l) {
    /* se a lista não for vazia */
    if (l->start != NULL) {
        /* se o tamanho da lista é 1, então removemos o único nodo */
        if (l->size == 1) {
            remove_first(item, l);
            return 1;
        } 
        t_node *aux_ptr = malloc(sizeof(t_node));
        if (aux_ptr == NULL) {
            printf("Falha de memória. Abortando.\n\n");
            return 0;
        }
        aux_ptr->next = l->start;
        /*enquanto não estamos no último nodo */
        while (aux_ptr->next->next->next != NULL) {
            aux_ptr->next = aux_ptr->next->next;
        }
        *item = aux_ptr->next->key;
        free(aux_ptr->next->next);
        aux_ptr->next->next = NULL;
        free(aux_ptr);
        l->size--;
        return 1;
    }
    return 0;
}

/* remove um nodo se ele é igual a chave */
int remove_item(int key, int *item, t_list *l) {
    /* se houver elementos na lista */
    if (! is_list_empty(l)) {
        /* se a primeira posição for igual achave nós a removemos */
        if (key == l->start->key) {
            remove_first(item, l);
            return 1;
        }
        /* garantimos que o tamanho da lista é maior ou igual a dois elementos */
        if (l->size > 1) {
            t_node *aux_ptr = malloc(sizeof(t_node));
            if (aux_ptr == NULL) {
                printf("Falha de memória. Abortando.\n");
                return 0;
            }
            aux_ptr->next = l->start;
            /* apontamos sempre uma posição antes do nodo que será removido */
            while (aux_ptr->next->next->next != NULL && aux_ptr->next->next->key != key) {
                aux_ptr->next = aux_ptr->next->next;
            }
            /* se acharmos o elemento ele é removido */
            if (aux_ptr->next->next->key == key) {
                t_node *temp_ptr = malloc(sizeof(t_node));
                if (temp_ptr == NULL) {
                    free(aux_ptr);
                    printf("Falha de memória. Abortando.\n");
                    return 0;
                }
                temp_ptr->next = aux_ptr->next->next;
                aux_ptr->next->next = temp_ptr->next->next;
                *item = temp_ptr->next->key;
                free(temp_ptr);
                free(aux_ptr);
                l->size--;
                return 1;
            }
            printf("elemento não encontrado.\n");
            free(aux_ptr);
            return 0;
        }
    }
    printf("elemento não encontrado.\n");
    return 0;
}

/* verificamos se o elemento chave está na lista */
int belongs_to_list(int key, t_list *l) {
    t_node *aux_ptr = malloc(sizeof(t_node));
    if (aux_ptr == NULL || is_list_empty(l)) {
        printf("Lista vazia ou falha de memória.");
        return 0;
    }
    aux_ptr->next = l->start;
    /* caminhamos até o último nodo procurando o elemento */
    while (aux_ptr->next->key != key && aux_ptr->next->next != NULL) { 
        aux_ptr->next = aux_ptr->next->next;
    }
    /* se encontramos, retornamos 1 */
    if (aux_ptr->next->key == key) {
        free(aux_ptr);
        aux_ptr = NULL;
        return 1;
    }
    free(aux_ptr);
    return 0;
}

 /* caminhamos até o último elemento da lista l */
 /* fazemos esse elemento apontar para o inicio da lista m */
int concatenate_lists(t_list *l, t_list *m) {
    t_node *aux_ptr = malloc(sizeof(t_node));
    if (aux_ptr == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    aux_ptr->next = l->start;
    while (aux_ptr->next->next != NULL) {
        aux_ptr->next = aux_ptr->next->next;
    }
    aux_ptr->next->next = m->start;
    free(aux_ptr);
    m->start = NULL;
    return 1;
}

int copy_list(t_list *l, t_list *m) {
    create_list(m);
    int i;
    int x;
    t_node *aux_ptr = malloc(sizeof(t_node));
    if (aux_ptr == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    aux_ptr->next = l->start;
    /* usamos o tamanho da lista para criar uma lista nova */
    /* e copiamos cada chave na lista nova */
    for (i = 0; i < l->size; ++i) {
        x = aux_ptr->next->key;
        insert_at_end(x, m);
        aux_ptr->next = aux_ptr->next->next;
    }
    free(aux_ptr);
    return 1;
}
