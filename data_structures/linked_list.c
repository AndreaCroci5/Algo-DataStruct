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

int is_an_empty_list(Nodeptr head) {
    return head == NULL;
}

int check_data_presence(Nodeptr head, int data) {
    if (is_an_empty_list(head))
        return 0;
    if (head->data == data)
        return 1;
    return check_data_presence(head->next, data);
}

Nodeptr head_insert(Nodeptr head, int data) {
    Nodeptr new_head;
    new_head = malloc(sizeof(Node));
    new_head->data = data;
    new_head-> next = head;
    return new_head;
}

Nodeptr tail_insert(Nodeptr head, int data) {
    if (is_an_empty_list(head))
        return head_insert(head, data);
    head->next = tail_insert(head->next, data);
    return head;
}



