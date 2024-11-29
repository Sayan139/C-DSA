#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void countnodes(struct node *head){
    int count = 0;
    if(head == NULL) printf("the linked list is empty");
    struct node *ptr = head; // this is the pointer which is going to iterate through the linkedlist
    while(ptr != NULL){
        count++;
        ptr = ptr->next; //iterating by evertime changing the next to next node
    }
    printf("the number of nodes in the single linked list: %d",count);
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;
    struct node *cur = malloc(sizeof(struct node));
    cur->data = 20;
    cur->next = NULL;
    head->next = cur;
    cur = malloc(sizeof(struct node));
    cur->data = 30;
    cur->next = NULL;
    head->next->next = cur; // the head->next is accessing the same node next part where the address of the next node is saved
    //and after that ->next is accessing the next part of the second node which stored the address of the third node so here its null
    // so the cur element is pointing the newly created node is given in the second node next part so now they are connected.
    countnodes(head);
}