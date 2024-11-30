#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node at a given 1-based position
void deleteNode(struct Node** ref, int position) {
    if (*ref == NULL || position <= 0) return; // List is empty or invalid position

    struct Node* temp = *ref;

    // If the head needs to be removed
    if (position == 1) {
        *ref = temp->next;
        free(temp);
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is beyond the list length
    if (temp == NULL || temp->next == NULL) return;

    // Node to be deleted
    struct Node* next = temp->next->next;

    free(temp->next);
    temp->next = next;
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

    // Delete node at position 3
    deleteNode(&head, 3);

    printf("List after deleting node at position 3: ");
    printList(head);

    return 0;
}
