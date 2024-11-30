#include <stdio.h>
#include <stdlib.h>

// Define the node structure for Doubly Circular Linked List
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct node** head, int value) {
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

        new_node->next = *head;
        (*head)->prev = new_node;
        new_node->prev = last;
        last->next = new_node;
        *head = new_node; // Update head
    }
}

// Function to insert a node at the end
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

// Function to insert a node after a specific node
void insertAfter(struct node* head, int prev_value, int new_value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    do {
        if (temp->data == prev_value) {
            struct node* new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = new_value;

            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next->prev = new_node;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node with value %d not found.\n", prev_value);
}

// Function to insert a node at a specific position
void insertAtPosition(struct node** head, int value, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;

    if (position == 1) {
        insertAtBeginning(head, value); // Insert at the beginning
        return;
    }

    struct node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
        if (temp == *head) {
            printf("Position is out of bounds.\n");
            return;
        }
    }

    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != *head) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
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

// Main function to test the addition functions
int main() {
    struct node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    
    // Print the list
    printf("Doubly Circular Linked List after insertions at the beginning: ");
    printList(head);

    // Insert nodes at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // Print the list
    printf("Doubly Circular Linked List after insertions at the end: ");
    printList(head);

    // Insert a node after a specific value
    insertAfter(head, 20, 25); // Insert 25 after 20
    
    // Print the list
    printf("Doubly Circular Linked List after inserting 25 after 20: ");
    printList(head);

    // Insert a node at a specific position
    insertAtPosition(&head, 35, 4); // Insert 35 at position 4
    
    // Print the list
    printf("Doubly Circular Linked List after inserting 35 at position 4: ");
    printList(head);

    return 0;
}
