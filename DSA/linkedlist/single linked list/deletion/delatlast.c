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
    struct node *temp2 = NULL;

    // Traverse to the second-last node
    while (temp->next != NULL) {
        temp2 = temp;
        temp = temp->next;
    }

    // Now temp points to the last node
    // temp2 points to the second-last node
    if (temp2 != NULL) {
        temp2->next = NULL; // Remove the last node
    }

    free(temp); // Free the last node
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
