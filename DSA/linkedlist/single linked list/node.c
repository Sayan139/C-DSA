#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next; // this is also called a self referential structure because it is calling it self or referring itself.
};
int main(){
    struct node *head =NULL;
    head = malloc(sizeof(struct node)); //now we created a node and head pointer is pointing to it
    head->data=45; // by the use of -> we can access the inside of the structure or function available inside the created node
    head->next=NULL;
    printf("the value of the node : %d",head->data);  
}