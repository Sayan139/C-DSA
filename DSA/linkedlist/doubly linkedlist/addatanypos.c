#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to add a node at a specific position
void addAtPosition(struct node** head, int value, int position) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;

    if (position == 1) { // Insert at the front
        new_node->next = *head;
        new_node->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = new_node;
        }

        *head = new_node;
        return;
    }

    struct node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) { // Position is beyond the current list length
        printf("Position out of bounds.\n");
        free(new_node);
        return;
    }

    // Insert the new node
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
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

    // Add nodes at specific positions
    addAtPosition(&head, 10, 1); // Add 10 at position 1
    addAtPosition(&head, 20, 2); // Add 20 at position 2
    addAtPosition(&head, 30, 2); // Add 30 at position 2
    addAtPosition(&head, 40, 1); // Add 40 at position 1

    // Print the list
    printf("Doubly Linked List: ");
    printList(head);

    return 0;
}
