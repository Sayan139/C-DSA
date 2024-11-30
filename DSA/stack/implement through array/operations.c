#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Define stack size

int stack[MAX];
int top = -1; // Initial condition: stack is empty

// Check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1; // or any sentinel value
    } else {
        return stack[top--];
    }
}

// Peek the top element
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Get the size of the stack
int size() {
    return top + 1;
}

int main() {
    // Example usage of the stack
    push(10);
    push(20);
    push(30);
    
    printf("Top element is %d\n", peek());

    printf("Popped element is %d\n", pop());
    printf("Current stack size: %d\n", size());

    return 0;
}
