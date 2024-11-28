#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head = malloc(sizeof(struct node));
    struct node *current = mallox(sizeof(struct node));
    head->data = 1;
    head->next = current;
    current->data = 2;
    current->next =NULL; 
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->next = NULL;
    head->next->next = current;
}