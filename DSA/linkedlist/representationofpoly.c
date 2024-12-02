#include <stdio.h>
#include <stdlib.h>

// Node structure for each term in the polynomial
struct Node {
    int coefficient; // Coefficient of the term
    int exponent;    // Exponent of the term
    struct Node* next; // Pointer to the next term
};

// Add a term at the end of the polynomial
void addTermAtEnd(struct Node** head, int coefficient, int exponent) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient; // Set coefficient
    newNode->exponent = exponent;       // Set exponent
    newNode->next = NULL;               // New node points to NULL

    if (*head == NULL) { // If the list is empty
        *head = newNode;
        return;
    }

    struct Node* current = *head; // Traverse to the end of the list
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode; // Add the new node at the end
}

// Display the polynomial in readable format
void displayPolynomial(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent); // Print term
        head = head->next;
        if (head != NULL) printf(" + "); // Add '+' between terms
    }
    printf("\n");
}

int main() {
    struct Node* polynomial = NULL; // Start with an empty polynomial

    // Add terms to the polynomial
    addTermAtEnd(&polynomial, 3, 2); // Add term 3x^2
    addTermAtEnd(&polynomial, 5, 1); // Add term 5x^1
    addTermAtEnd(&polynomial, 2, 0); // Add term 2x^0

    printf("Polynomial: ");
    displayPolynomial(polynomial); // Display the polynomial

    return 0;
}
