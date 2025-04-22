/**
 * @file        deque.c
 * @author      Andrea Croci
 * @date        2025-03-04
 * @brief       Implementation of a deque
 *
 * @details     This file implements a deque with
 *              various operations such as pushfront, pushback, popfront
 *              popback, empty and destroy
 */


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Node structure for the deque.
 */
typedef struct Nd {
    int data;              /**< Integer value stored in the node */
    struct Nd *next;       /**< Pointer to the next node */
    struct Nd *prev;       /**< Pointer to the previous node */
} Node;

/**
 * @brief Defines a pointer to a Node.
 */
typedef Node * Nodeptr;

/**
 * @brief Structure representing a deque with head and tail pointers.
 */
typedef struct {
    Node *head;            /**< Pointer to the front of the deque */
    Node *tail;            /**< Pointer to the back of the deque */
} Deque;

/**
 * @brief Defines a pointer to a Deque.
 */
typedef Deque * Dequeptr;

/**
 * @brief Creates and initializes an empty deque.
 * @return Pointer to the newly created deque.
 */
Deque* create_Deque() {
    Dequeptr q = (Deque*) malloc(sizeof(Deque));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

/**
 * @brief Inserts an element at the front of the deque.
 * @param q Pointer to the deque.
 * @param value The integer value to insert.
 */
void push_front(Dequeptr q, int value) {
    Nodeptr new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = q->head;

    if (q->head) q->head->prev = new_node;
    q->head = new_node;
    if (!q->tail) q->tail = new_node;
}

/**
 * @brief Inserts an element at the back of the deque.
 * @param q Pointer to the deque.
 * @param value The integer value to insert.
 */
void push_back(Dequeptr q, int value) {
    Nodeptr new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = q->tail;

    if (q->tail) q->tail->next = new_node;
    q->tail = new_node;
    if (!q->head) q->head = new_node;
}

/**
 * @brief Removes and returns the element from the front of the deque.
 * @param q Pointer to the deque.
 * @return The integer value removed, or 404 if the deque is empty.
 */
int pop_front(Dequeptr q) {
    if (!q->head) return 404; // ERROR
    Nodeptr temp = q->head;
    int value = temp->data;
    q->head = q->head->next;
    if (q->head) q->head->prev = NULL;
    else q->tail = NULL;
    free(temp);

    return value;
}

/**
 * @brief Removes and returns the element from the back of the deque.
 * @param q Pointer to the deque.
 * @return The integer value removed, or 404 if the deque is empty.
 */
int pop_back(Dequeptr q) {
    if (!q->tail) return 404; // ERROR
    Nodeptr temp = q->tail;
    int value = temp->data;
    q->tail = q->tail->prev;
    if (q->tail) q->tail->next = NULL;
    else q->head = NULL;
    free(temp);

    return value;
}

/**
 * @brief Checks if the deque is empty.
 * @param q Pointer to the deque.
 * @return 1 if empty, 0 otherwise.
 */
int is_empty(Dequeptr q) {
    return q->head == NULL;
}

/**
 * @brief Frees all the memory associated with the deque.
 * @param q Pointer to the deque.
 */
void destroy(Dequeptr q) {
    while (!is_empty(q)) pop_front(q);
    free(q);
}

/**
 * @brief Prints the contents of the deque from front to back.
 * @param q Pointer to the deque.
 */
void print_Deque(Dequeptr q) {
    Nodeptr current = q->head;
    while (current) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * @brief Example usage of deque operations.
 */
int main() {
    Deque *dq = create_Deque();

    push_back(dq, 1);
    push_back(dq, 2);
    push_back(dq, 3);
    push_front(dq, 0);
    print_Deque(dq);

    int value = -100;
    value = pop_front(dq);
    print_Deque(dq);
    printf("Value popped: %d\n", value);

    value = pop_back(dq);
    print_Deque(dq);
    printf("Value popped: %d\n", value);

    value = pop_front(dq);
    print_Deque(dq);
    printf("Value popped: %d\n", value);

    destroy(dq);
    return 0;
}
