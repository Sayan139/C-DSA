#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to delete the last node
void deleteLast(struct node** head) {
    if (*head == NULL) { // If the list is empty
        printf("The list is empty!\n");
        return;
    }

    struct node* temp = *head;

    // If there is only one node in the list
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update the second last node's next pointer to NULL
    temp->prev->next = NULL;
    free(temp); // Free the last node
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

    // Delete the last node
    deleteLast(&head);

    // Print the list after deletion
    printf("Doubly Linked List after deleting the last node: ");
    printList(head);

    return 0;
}
