#include <stdio.h>
#include "list.h"

#define MAX 5


int test_insert_at_beginning(t_list *l) {
    int i;

    for (i=1; i<=MAX; i++)
        if (! insert_at_beginning(2*i,l))
            return 0;
    return 1;
}

int test_insert_at_end(t_list *l) {
    int i;

    for (i=1; i<=MAX; i++)
        if (! insert_at_end(2*i-1,l))
            return 0;
    return 1;
}

int test_insert_in_order(t_list *l) {
    if (! insert_in_order(8,l)) return 0;
    if (! insert_in_order(10,l)) return 0;
    if (! insert_in_order(0,l)) return 0;
    if (! insert_in_order(9,l)) return 0;
    if (! insert_in_order(12,l)) return 0;
    if (! insert_in_order(2,l)) return 0;
    if (! insert_in_order(3,l)) return 0;
    return 1;
}

int create_lists(t_list *l, t_list *m, t_list *o, t_list *c) {
    printf("Criando lista l\n");
    if (! create_list(l)) {
        printf("Erro: lista l nao foi criada.");
        return 0;
    }

    printf("Criando lista m\n");
    if (! create_list(m)) {
        printf("Erro: lista m nao foi criada.");
        return 0;
    }

    printf("Criando lista o\n");
    if (! create_list(o)) {
        printf("Erro: lista o nao foi criada.");
        return 0;
    }

    printf("Criando lista c\n");
    if (! create_list(c)) {
        printf("Erro: lista c nao foi criada.");
        return 0;
    }
    return 1;
}

int test_insertions(t_list *l, t_list *m, t_list *o) {
    printf("Teste: inserir no inicio\n");
    if (! test_insert_at_beginning(l)) {
        printf("Insercao no inicio falhou...");
        return 0;
    }
    printf("l: ");
    print_list(l);
    printf("Teste: inserir no fim\n");
    if (! test_insert_at_end(m)) {
        printf("Insercao no fim falhou...");
        return 0;
    }
    printf("m: ");
    print_list(m);

    printf("Teste: inserir ordenado\n");
    if (! test_insert_in_order(o)) {
        printf("Insercao ordenada falhou...");
        return 0;
    }
    printf("o: ");
    print_list(o);
    return 1;
}

int test_copy(t_list *o, t_list *c) {

    printf("Teste: copia o em c\n");
    if (! copy_list(o,c)) {
        printf("copia falhou...");
        return 0;
    }
    printf("c: ");
    print_list(c);

    return 1;
}

int test_concatenation(t_list *l, t_list *m) {
    printf("Concatenando m em l\n");
    if (! concatenate_lists(l,m)) {
        printf("concatenacao falhou...");
        return 0;
    }
    printf("l: ");
    print_list(l);
    printf("m:\n");
    print_list(m);
    return 1;
}

int test_removals(t_list *l, t_list *o, t_list *c) {
    int item;

    printf("Teste: remocoes\n");
    printf("Remocao no inicio: remove todos de l\n");
    while (! is_list_empty(l))
        if (! remove_first(&item,l)) return 0;
    printf("l: ");
    print_list(l);
    printf("\n");
    printf("Remocao no final: remove todos de o\n");
    /*while (! is_list_empty(o))*/
    while (o->size)
        if (! remove_last(&item,o)) return 0;
    printf("o: ");
    print_list(o);
    printf("\n");

    printf("Remocao em ordem: remove elementos selecionados de c\n");
    if (remove_item(0,&item,c)) printf("removeu %d\n",0);
    if (remove_item(8,&item,c)) printf("removeu %d\n",8);
    if (remove_item(7,&item,c)) printf("removeu %d\n",7);
    if (remove_item(12,&item,c)) printf("removeu %d\n",12);
    printf("c: ");
    print_list(c);
    return 1;
}

void destroy_all_lists(t_list *l, t_list *m, t_list *o, t_list *c) {
    printf("destroi l\n");
    destroy_list(l);
    print_list(l);
    printf("destroi m\n");
    destroy_list(m);
    print_list(m);
    printf("destroi o\n");
    destroy_list(o);
    print_list(o);
    printf("destroi c\n");
    destroy_list(c);
    print_list(c);
}

void test_search(t_list *c) {
    if (belongs_to_list(6,c))
        printf("%d encontrado.\n",6);
    else
        printf("%d nao encontrado.\n",6);
    if (belongs_to_list(2,c))
        printf("%d encontrado.\n",2);
    else
        printf("%d nao encontrado.\n",2);
}

int main() {
    t_list l, m, o, c; 

    if (! create_lists(&l,&m,&o,&c)) return 1;
    if (! test_insertions(&l,&m,&o)) return 1; 
    if (! test_copy(&o,&c)) return 1; 
    if (! test_concatenation(&l,&m)) return 1; 
    if (! test_removals(&l, &o, &c)) return 1; 
    test_search(&c);
    destroy_all_lists(&l, &m, &o, &c);

    return 0;
}
