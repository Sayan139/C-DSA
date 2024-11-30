#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* deleteAtLast(struct node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *temp = head;

    // Traverse the list to find the second last node
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    // Now temp points to the second-last node
    free(temp->next);  // Free the last node
    temp->next = NULL; // Set second last node's next to NULL

    return head;
}

void printTheList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct node *ptr = head;
    printf("HEAD");
    while (ptr != NULL) {
        printf(" -> %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" -> NULL\n");
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *current = malloc(sizeof(struct node));

    head->data = 1;
    head->next = current;
    current->data = 2;
    current->next = NULL;

    current = malloc(sizeof(struct node));
    current->data = 3;
    current->next = NULL;
    head->next->next = current;

    current = malloc(sizeof(struct node));
    current->data = 4;
    current->next = NULL;
    head->next->next->next = current;

    printTheList(head);

    head = deleteAtLast(head);
    printf("After deleting last node:\n");
    printTheList(head);

    head = deleteAtLast(head);
    printf("After deleting last node:\n");
    printTheList(head);

    head = deleteAtLast(head);
    printf("After deleting last node:\n");
    printTheList(head);

    head = deleteAtLast(head);
    printf("After deleting last node:\n");
    printTheList(head);

    return 0;
}
