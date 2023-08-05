#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element %d, stack is full.\n", element);
        return;
    }

    stack->data[++stack->top] = element;
    printf("Element %d pushed onto the stack.\n", element);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1;
    }

    int poppedElement = stack->data[stack->top--];
    return poppedElement;
}

// Function to peek the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    }

    return stack->data[stack->top];
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    int poppedElement = pop(&stack);
    if (poppedElement != -1) {
        printf("Popped element: %d\n", poppedElement);
    }

    printf("Top element after pop: %d\n", peek(&stack));

    return 0;
}

