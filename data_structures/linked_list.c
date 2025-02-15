//
// Created by Andrea Croci on 15/02/25.
//
#include <stdlib.h>

typedef struct Nd {
    int data;
    struct Nd * next;
} Node;

typedef Node * Nodeptr;

void search_node_from_data(Nodeptr head, int data) {
    Nodeptr ptr = head;
    while (ptr != NULL && ptr->data != data) {
        ptr = ptr->next;
    }
}

/* For variant
void search_node_from_data(Nodeptr head, int data) {
    Nodeptr ptr;
   for (ptr= head; ptr!=NULL && ptr->data!=data; ptr=ptr->next) {
    }
}
*/

int list_length(Nodeptr head) {
    int counter = 0;
    Nodeptr ptr;
    for (ptr= head; ptr!=NULL; ptr=ptr->next) {
        counter++;
    }
    return counter;
}

Nodeptr get_last_Node(Nodeptr head) {
    Nodeptr ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}
