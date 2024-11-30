#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
void reverseList(struct Node** ref) {
    struct Node* prev = NULL;
    struct Node* current = *ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to the current node
        current = next;       // Move to the next node
    }

    *ref = prev; // Update head to the new front
}

// Utility functions to add a node and print the list
void push(struct Node** ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *ref;
    *ref = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating a linked list
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original list: ");
    printList(head);

    // Reverse the linked list
    reverseList(&head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
