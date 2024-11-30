#include <stdio.h>
#include <stdlib.h>

// Define the node structure for Doubly Circular Linked List
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to insert a node at the end (used for testing)
void insertAtEnd(struct node** head, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;

    if (*head == NULL) {
        new_node->next = new_node; // Point to itself
        new_node->prev = new_node; // Point to itself
        *head = new_node;
    } else {
        struct node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        new_node->next = *head; // Point to head
        new_node->prev = last;
        last->next = new_node;
        (*head)->prev = new_node;
    }
}

// Function to delete the first node
void deleteFirst(struct node** head) {
    if (*head == NULL) { // List is empty
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;

    // If there is only one node in the list
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    // Set the last node's next to point to the second node
    struct node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    *head = temp->next;
    (*head)->prev = last;
    last->next = *head;

    // Free the first node
    free(temp);
}

// Function to delete the last node
void deleteLast(struct node** head) {
    if (*head == NULL) { // List is empty
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;

    // If there is only one node
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    // Traverse to the second last node
    struct node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    // Update the second last node's next to point to the head
    last->prev->next = *head;
    (*head)->prev = last->prev;

    // Free the last node
    free(last);
}

// Function to delete a node at a specific position
void deleteAtPosition(struct node** head, int position) {
    if (*head == NULL || position <= 0) { // List is empty or invalid position
        printf("Invalid position or empty list.\n");
        return;
    }

    struct node* temp = *head;

    // If position is 1, delete the first node
    if (position == 1) {
        deleteFirst(head);
        return;
    }

    // Traverse to the node before the position to delete
    struct node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) {
            printf("Position out of bounds.\n");
            return;
        }
    }

    // If position is valid, delete the node
    if (temp != NULL) {
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
    }
}

// Function to delete a node by value
void deleteByValue(struct node** head, int value) {
    if (*head == NULL) { // List is empty
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

    // If the head node itself holds the value
    if (temp->data == value) {
        deleteFirst(head);
        return;
    }

    // Traverse to find the node with the given value
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != value);

    // If the value is found, delete the node
    if (temp->data == value) {
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}

// Function to print the list
void printList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function to test the deletion operations
int main() {
    struct node* head = NULL;

    // Insert nodes at the end (for testing)
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Print the list
    printf("Doubly Circular Linked List after insertions: ");
    printList(head);

    // Delete the first node
    deleteFirst(&head);
    printf("Doubly Circular Linked List after deleting first node: ");
    printList(head);

    // Delete the last node
    deleteLast(&head);
    printf("Doubly Circular Linked List after deleting last node: ");
    printList(head);

    // Delete the node at position 2
    deleteAtPosition(&head, 2);
    printf("Doubly Circular Linked List after deleting node at position 2: ");
    printList(head);

    // Delete the node with value 30
    deleteByValue(&head, 30);
    printf("Doubly Circular Linked List after deleting node with value 30: ");
    printList(head);

    return 0;
}
