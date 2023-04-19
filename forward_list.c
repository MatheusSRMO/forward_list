#include "forward_list.h"
#include <stdlib.h>
#include <stdio.h>

// cria uma lista
ForwardList* forward_list_construct() {
    ForwardList *fList = (ForwardList *)malloc(sizeof(ForwardList));
    fList->head = NULL;
    fList->size = 0;
    return fList;
}

// retorna o número de elementos na lista
int forward_list_size(ForwardList* l) {
    return l->size;
}

// adiciona um item no início da lista
void forward_list_push_front(ForwardList* l, data_type val) {
    l->head = node_construct(val, l->head);
    l->size++;
}

// mostra a lista na tela
void forward_list_print(ForwardList* l, void (*print_fn)(data_type)) {
    printf("[");
    Node *np = l->head;
    while (np != NULL) {
        print_fn(np->value);
        np = np->next;
        if (np != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

// retorna o i-ésimo elemento da lista
data_type forward_list_get(ForwardList* l, int i) {
    Node *np = l->head;
    for (int j = 0; j < i; j++) {
        np = np->next;
    }
    return np->value;
}

// remove o primeiro elemento
data_type forward_list_pop_front(ForwardList* l) {
    l->size--;
    Node *np = l->head;
    data_type value = np->value;
    l->head = l->head->next;
    free(np);
    return value;
}

// retorna uma lista contendo o reverso de outra
ForwardList* forward_list_reverse(ForwardList* l) {
    ForwardList *fList = forward_list_construct();
    Node *np = l->head;
    while (np != NULL) {
        forward_list_push_front(fList, np->value);
        np = np->next;
    }
    return fList;
}

void forward_list_destroy(ForwardList* l) {
    Node *np = l->head;
    while (np != NULL) {
        Node *aux = np;
        np = np->next;
        free(aux);
    }
    free(l);
}

// remove todos os nós da lista
void forward_list_clear(ForwardList* l) {
    forward_list_destroy(l);
    l = forward_list_construct();
}
