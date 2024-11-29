#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void frontdel(struct node **head){
    if(*head == NULL){
        printf("the list is empty! \n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void printthelist(struct node *head){
    if(head == NULL){
        printf("the list is empty!\n");
        return; // we have to return it becuase if not it will excute the rest of the code if condition is true
    }
    struct node *ptr = head;
    printf("HEAD");
    while(ptr != NULL){ //we have to iterate till the last node where next element is null
        printf("->%d",ptr->data);
        ptr = ptr->next;
    }
    printf("->NULL\n");
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    struct node *current = malloc(sizeof(struct node));
    head->data = 1;
    head->next = current;
    current->data = 2;
    current->next =NULL; 
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->next = NULL;
    head->next->next = current;
    current = malloc(sizeof(struct node));
    current->data = 4;
    current->next = NULL;
    head->next->next->next = current;
    printthelist(head);
    frontdel(&head);
    printthelist(head);
}