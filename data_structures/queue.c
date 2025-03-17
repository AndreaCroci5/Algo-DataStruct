/**
 * @file        queue.c
 * @author      Andrea Croci
 * @date        2025-03-04
 * @brief       Implementation of a queue
 *
 * @details     This file implements a queue with
 *              various operations such as enqueue, dequeue, print, and destroy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

/**
 * @brief Represents a single node in the list, containing data and a pointer to the next node.
 */
typedef struct Nd {
    int data;
    struct Nd * next;
} Node;

/**
 * @brief Defines a pointer to a Node.
 */
typedef Node * Nodeptr;

/**
 * @brief Represents the queue structure with head and tail pointers.
 */
typedef struct {
    Nodeptr head;   /**< Pointer to the first node in the queue */
    Nodeptr tail;   /**< Pointer to the last node in the queue */
} Queue;

/**
 * @brief Initializes the queue by setting head and tail to NULL.
 *
 * @param q Pointer to the queue structure.
 */
void init_queue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

/**
 * @brief Checks if the queue is empty.
 *
 * @param q Pointer to the queue structure.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int is_empty(Queue *q) {
    return q->head == NULL;
}

/**
 * @brief Inserts a new element at the end of the queue.
 *
 * @param q Pointer to the queue structure.
 * @param value The integer value to enqueue.
 */
void enqueue(Queue *q, int value) {
    Nodeptr new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

/**
 * @brief Removes and returns the front element from the queue.
 *
 * @param q Pointer to the queue structure.
 * @return The dequeued integer value, or -1 if the queue is empty.
 */
int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue underflow\n");
        return -1;
    }

    Nodeptr tmp = q->head;
    int value = tmp->data;
    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(tmp);
    return value;
}

/**
 * @brief Prints the elements of the queue in order.
 *
 * @param q Pointer to the queue structure.
 */
void print_queue(Queue *q) {
    Nodeptr tmp = q->head;
    while (tmp != NULL) {
        printf("%d --> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

/**
 * @brief Frees all nodes in the queue, releasing allocated memory.
 *
 * @param q Pointer to the queue structure.
 */
void free_queue(Queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
}

/**
 * @brief Main function to test the queue implementation.
 *
 * @return 0 upon successful execution.
 */
int main() {
    Queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print_queue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    print_queue(&q);

    free_queue(&q);
    return 0;
}
