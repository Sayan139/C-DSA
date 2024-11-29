#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void addattheendofthelist(struct node *head,int value){
    struct node *cur = malloc(sizeof(struct node));
    struct node *ptr = head;
    cur->data = value;
    cur->next = NULL;
    while(ptr->next != NULL){ //ptr->next because when the iteration come to the last section of the list then if 
    // i  do ptr != nULL THEN it will go to the null part of the list where nothing exist so in order to save from that i
    // going till ptr->next so it will check its the last elements
        ptr = ptr->next;
    }
    ptr->next = cur;
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
    head->data = 10;
    head->next = NULL;
    struct node *cur = malloc(sizeof(struct node));
    cur->data = 20;
    cur->next = NULL;
    head->next = cur;
    cur = malloc(sizeof(struct node));
    cur->data = 30;
    cur->next = NULL;
    head->next->next = cur;
    printthelist(head);
    printf("enter the value of the number you want to enter : ");
    int n;
    scanf("%d",&n);
    printf("orginal list: \n");
    printthelist(head);
    printf("new list: \n");
    addattheendofthelist(head,n);
    printthelist(head);
}