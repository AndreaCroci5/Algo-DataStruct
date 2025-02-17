/**
* @file        linked_list.c
 * @author      Andrea Croci
 * @date        2025-02-15
 * @brief       Implementation of a linled list.
 *
 * @details     This file implements a simple linked list with
 *              various operations such as insertion, deletion and search
 *              expressed as functions and procedures.
 *
 */
#include <stdio.h>
#include <stdlib.h>

// LIST STRUCTURE AND TYPE DECLARATION
/**
 * @brief Represent a single node on the list containing data and a pointer to the next node
 */
typedef struct Nd {
    int data;
    struct Nd * next;
} Node;

/**
 * @brief Represent a pointer to Node
 */
typedef Node * Nodeptr;

// FUNCTIONS

// Search
/**
 * @brief Searches a Node in a linked list by its data
 * 
 * @param head Pointer to the head of the linked list
 * @param data Data contained in the node to search
 * @return 
 */
Nodeptr search_node_from_data(Nodeptr head, int data) {
    Nodeptr ptr = head;
    while (ptr != NULL && ptr->data != data) {
        ptr = ptr->next;
    }
    return ptr;
}

/* // Search with for form variant
void search_node_from_data(Nodeptr head, int data) {
    Nodeptr ptr;
   for (ptr= head; ptr!=NULL && ptr->data!=data; ptr=ptr->next) {
    }
}
*/

/**
 * @brief Returns the length of a linked list by passing the head node to the function
 *
 * @param head Pointer to the head of the linked list
 * @return Length of the linked list
 */
int list_length(Nodeptr head) {
    int counter = 0;
    Nodeptr ptr;
    for (ptr= head; ptr!=NULL; ptr=ptr->next) {
        counter++;
    }
    return counter;
}

/**
 * @brief Returns the pointer to the last node of a linked list by passing the head node to the function
 *
 * @param head Pointer to the head of the linked list
 * @return Pointer to the last node of the list
 */
Nodeptr get_last_Node(Nodeptr head) {
    Nodeptr ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}

// Checking

/**
 * @brief Check if a linked list is empty
 *
 * @param head Pointer to the head of the linked list
 * @return 1 if the list is empty, 0 otherwise
 */
int is_an_empty_list(Nodeptr head) {
    return head == NULL;
}

/**
 * @brief Check if a node containing a specific data is present in the linked list
 *
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the target node
 * @return 1 if the node exists, 0 otherwise
 */
int check_data_presence(Nodeptr head, int data) {
    if (is_an_empty_list(head))
        return 0;
    if (head->data == data)
        return 1;
    return check_data_presence(head->next, data);
}

// Insertion

/**
 @brief Insert a new node on the head of a linked list
 *
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the new node
 * @return Pointer to the new head of the linked list
 */
Nodeptr head_insert(Nodeptr head, int data) {
    Nodeptr new_head;
    new_head = malloc(sizeof(Node));
    new_head->data = data;
    new_head-> next = head;
    return new_head;
}

/**
 * @brief Insert a new node on the tail of a linked list
 *
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the new node
 * @return Pointer to the last node of the linked list
 */
Nodeptr tail_insert(Nodeptr head, int data) {
    if (is_an_empty_list(head))
        return head_insert(head, data);
    head->next = tail_insert(head->next, data);
    return head;
}

// Deletion

/**
 * @brief Delete a node containing a specific data
 *
 * @param head Pointer to the head of the linked list
 * @param data  Value of the data contained in the target node
 * @return Pointer to the head of modified linked list
 */
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

/**
 * @brief Delete a node containing a specific data and also duplicated nodes if present
 *
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the target node or nodes
 * @return Pointer to the head of modified linked list
 */
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

/**
 * @brief Destroy and deallocate a linked list by passing the head of the list as input
 *
 * @param head Pointer to the head of the linked list
 */
void destroy_list(Nodeptr head) {
    if (!is_an_empty_list(head)) {
        destroy_list(head->next);
        free(head);
    }
}

// Print

/**
 * @brief Print the data contained in the linked list starting from the head
 *
 * @param head Pointer to the head of the linked list
 */
void print_list(Nodeptr head) {
    if (is_an_empty_list(head))
        printf("--|");
    else {
        if (!is_an_empty_list(head->next))
            printf("%d --> ", head->data);
        print_list(head->next);
    }
}

/**
 * @brief Print the data contained in the linked list starting from the tail
 *
 * @param head Pointer to the head of the linked list
 */
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

/**
 * @brief Reverse a linked list
 *
 * @param head Pointer to the head of the linked list
 * @return Pointer to the new head of the linked list (old tail)
 */
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

/**
 * @brief Insert a new node on the head of a linked list
 *
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the new node
 */
void head_insertion_procedure(Nodeptr * head, int data) {
    Nodeptr ptr;
    ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}

/**
 * @brief Insert a new node on the tail of a linked list
 *
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the new node
 */
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

/**
 * @brief Insert a node in a specific position inside an ordered linked list, in order to keep the order
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the new node
 */
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

/**
 * @brief Delete a node containing a specific data
 *
 * @param head Pointer to the head of the linked list
 * @param data Value of the data contained in the target node
 */
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