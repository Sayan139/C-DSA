#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to delete a node at a given position
void deleteAtPosition(struct node** head, int position) {
    if (*head == NULL || position <= 0) { // If the list is empty or invalid position
        printf("Invalid position or empty list!\n");
        return;
    }

    struct node* temp = *head;

    // If position is 1, delete the first node
    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Traverse to the node at the given position
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // If position is beyond the list length
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    // Update the next and prev pointers of the surrounding nodes
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp); // Free the node
}

// Function to add a node at the end
void addAtEnd(struct node** head, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) { // If the list is empty
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    struct node* temp = *head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update pointers to add the new node at the end
    temp->next = new_node;
    new_node->prev = temp;
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

    // Add nodes to the list
    addAtEnd(&head, 10);
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    addAtEnd(&head, 40);

    // Print the list
    printf("Doubly Linked List: ");
    printList(head);

    // Delete the node at position 2
    deleteAtPosition(&head, 2);  // Delete node at position 2

    // Print the list after deletion
    printf("Doubly Linked List after deleting the node at position 2: ");
    printList(head);

    return 0;
}
