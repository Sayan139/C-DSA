#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to add a node at the front
void addAtFront(struct node** head, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    printf("HEAD");
    while (temp != NULL) {
        printf(" <-> %d", temp->data);
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

// Main function
int main() {
    struct node* head = NULL;

    // Add nodes at the front
    addAtFront(&head, 10);
    addAtFront(&head, 20);
    addAtFront(&head, 30);

    // Print the list
    printf("Doubly Linked List: ");
    printList(head);

    return 0;
}
