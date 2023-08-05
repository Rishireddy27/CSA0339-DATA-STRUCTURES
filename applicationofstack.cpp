#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isdigit() function

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

// Function to evaluate a postfix expression
int evaluatePostfixExpression(const char* expression) {
    struct Stack stack;
    initStack(&stack);

    int i, operand1, operand2;
    char current;

    for (i = 0; expression[i] != '\0'; i++) {
        current = expression[i];

        if (isdigit(current)) {
            push(&stack, current - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (current) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", current);
                    return -1;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char postfixExpression[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfixExpression, MAX_SIZE, stdin);

    int result = evaluatePostfixExpression(postfixExpression);
    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}

