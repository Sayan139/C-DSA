#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node  *addatfront(struct node *head,int value){ //this is the example of the pass by value so here we have to return the
//adress of the new node so that it can copup with it thats why the return type is struct node
    struct node *cur = malloc(sizeof(struct node));
    cur->data = value;
    cur->next = head;
    return cur;
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
    head = addatfront(head,n);
    printthelist(head);
}