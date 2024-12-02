#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;           // Position of the person
    struct Node* next;  // Pointer to the next node
};

// Function to create a circular linked list of size N
struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head; // Link back to head for circular list

        if (!head) { 
            head = newNode; // Initialize the head
        } else {
            temp->next = newNode; // Link the previous node to the new one
        }
        temp = newNode;
    }
    temp->next = head; // Complete the circular link
    return head;
}

// Function to solve the Josephus problem using the linked list
int josephus(struct Node* head, int k) {
    struct Node *current = head, *prev = NULL;

    while (current->next != current) { // Continue until one node remains
        for (int i = 1; i < k; i++) { // Move k-1 steps
            prev = current;
            current = current->next;
        }
        // Eliminate the k-th node
        prev->next = current->next;
        printf("Eliminated: %d\n", current->data);
        free(current); // Free memory of eliminated node
        current = prev->next; // Move to the next node
    }
    return current->data; // Return the position of the last person
}

int main() {
    int n, k;
    printf("Enter the number of people (N): ");
    scanf("%d", &n);
    printf("Enter the step size (K): ");
    scanf("%d", &k);

    struct Node* head = createCircularList(n); // Create the list
    int safePosition = josephus(head, k);     // Solve the problem

    printf("The safe position is: %d\n", safePosition);
    return 0;
}
