//
// Created by Andrea Croci on 15/02/25.
//
#include <stdio.h>
#include <stdlib.h>

// LIST STRUCTURE AND TYPE DECLARATION
typedef struct Nd {
    int data;
    struct Nd * next;
} Node;

typedef Node * Nodeptr;

// FUNCTIONS

// Search
Nodeptr search_node_from_data(Nodeptr head, int data) {
    Nodeptr ptr = head;
    while (ptr != NULL && ptr->data != data) {
        ptr = ptr->next;
    }
    return ptr;
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

// Checking

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

// Insertion

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

// Deletion

Nodeptr delete_node(Nodeptr head, int data) {
    Nodeptr tmp_node;
    if (!is_an_empty_list(head)) {
        if (head->data == data) {
            tmp_node = head->next;
            free(head);
            return tmp_node;
        } else {
            head->next = delete_node(head->next, data);
        }
    }
    return head;
}

Nodeptr delete_node_w_duplicates(Nodeptr head, int data) {
    Nodeptr tmp_node;
    if (!is_an_empty_list(head)) {
        if (head->data == data) {
            tmp_node = head->next;
            free(head);
            return delete_node_w_duplicates(tmp_node, data);
        } else {
            head->next = delete_node_w_duplicates(head->next, data);
        }
    }
    return head;
}

void destroy_list(Nodeptr head) {
    if (!is_an_empty_list(head)) {
        destroy_list(head->next);
        free(head);
    }
}

// Print

void print_list(Nodeptr head) {
    if (is_an_empty_list(head))
        printf("--|");
    else {
        if (!is_an_empty_list(head->next))
            printf("%d --> ", head->data);
        print_list(head->next);
    }
}

void print_list_reverse(Nodeptr head) {
    if (is_an_empty_list(head))
        printf("|--");
    else {
        print_list_reverse(head->next);
        if (!is_an_empty_list(head->next))
            printf("<--");
        printf("%d", head->data);
    }
}

// Reverse

Nodeptr reverse_list(Nodeptr head) {
    Nodeptr ptr, new_head;
    if (is_an_empty_list(head) || is_an_empty_list(head->next))
        return head;
    ptr = head->next;
    new_head = reverse_list(head->next);
    ptr->next = head;
    head->next = NULL;
    return new_head;
}


// PROCEDURES

// Insertion

void head_insertion_procedure(Nodeptr * head, int data) {
    Nodeptr ptr;
    ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}

void tail_insertion_procedure(Nodeptr * head, int data ) {
    Nodeptr ptr;
    if (is_an_empty_list(*head)) {
        ptr = malloc(sizeof(Node));
        ptr->next = NULL;
        ptr->data = data;
        *head = ptr;
    } else {
        tail_insertion_procedure( &((*head)->next), data );
    }
}

void specific_insertion_procedure_in_ordered_list(Nodeptr * head, int data) {
    Nodeptr ptr, curr_ptr, prev_ptr=NULL;
    curr_ptr = *head;
    while (curr_ptr != NULL && data > curr_ptr->data)  {
        prev_ptr = curr_ptr;
        curr_ptr = curr_ptr->next;
    }
    ptr = malloc(sizeof(Nodeptr));
    ptr->data = data;
    ptr->next = curr_ptr;
    if( prev_ptr != NULL )
        prev_ptr->next = ptr;
    else
        *head = ptr;
}

void delete_node_procedure(Nodeptr * head, int data) {
    Nodeptr tmp_ptr;
    if(!is_an_empty_list(*head) )
        if((*head)->data == data ) {
            tmp_ptr = *head;
            *head = get_last_Node(*head);
            free(tmp_ptr);
        }
        else delete_node_procedure( &((*head)->next), data );
}