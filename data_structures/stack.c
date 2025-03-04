/**
* @file         stack.c
 * @author      Andrea Croci
 * @date        2025-02-17
 * @brief       Implementation of a stack
 *
 * @details     This file implements a stack with
 *              various operations such as push, pop, peek and destroy
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

#define ERROR 404

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

/**
 * @brief Represent the stack structure
 */
typedef struct {
    Nodeptr top;
} Stack;

/**
 * @brief Initialize an empty stack
 */
void initStack(Stack *s) {
    s->top = NULL;
}

/**
 * @brief Push an element onto the stack
 */
void push(Stack *s, int value) {
    Nodeptr new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed");
        return;
    }
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

/**
 * @brief Pop an element from the stack
 */
int pop(Stack *s) {
    if (s->top == NULL) {
        printf("The Stack is empty! Operation Failed");
        return ERROR;
    }

    Nodeptr temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);

    return value;
}

/**
 * @brief Check if the stack is empty
 */
int isEmpty(Stack *s) {
    return s->top == NULL;
}

/**
 * @brief Peek at the top element of the stack
 */
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("The Stack is empty!");
        return ERROR;
    }
    return s->top->data;
}

/**
 * @brief Free all nodes in the stack
 */
void freeStack(Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

/**
 * @brief Test the stack implementation
 */
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s)); // Should indicate stack underflow

    freeStack(&s);
    return 0;
}

