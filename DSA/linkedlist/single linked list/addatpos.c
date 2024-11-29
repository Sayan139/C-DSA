#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addatfront(struct node **head, int value)
{
    struct node *cur = malloc(sizeof(struct node));
    cur->data = value;
    cur->next = *head;
    *head = cur;
}
void addattheendofthelist(struct node **head, int value)
{
    struct node *cur = malloc(sizeof(struct node));
    struct node *ptr = *head;
    cur->data = value;
    cur->next = NULL;
    if (*head == NULL)
    {
        *head = cur; // Handle the case when the list is empty
        return;
    }
    while (ptr->next != NULL)
    { // ptr->next because when the iteration come to the last section of the list then if
        // i  do ptr != nULL THEN it will go to the null part of the list where nothing exist so in order to save from that i
        // going till ptr->next so it will check its the last elements
        ptr = ptr->next;
    }
    ptr->next = cur;
}
void addatpos(struct node **head, int value, int pos)
{
    if (pos < 1)
    {
        addatfront(&*head,value);
        return;
    }
    struct node *ptr = *head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = value;
    ptr2->next = NULL;
    pos--;
    while(pos > 1 && ptr != NULL){
        ptr = ptr->next;
        pos--;
    }
    if(ptr == NULL){
        addattheendofthelist(head,value);
        return;
    }
    ptr2->next = ptr->next; // first we have to assign the next part of the new value to the face of the pos+1 value thats why
    // the ptr->next menas thats the pos which result in reaching the pos-1 is going the the actual position by ptr->next
    // and changing the new value next part to the actual position
    ptr->next = ptr2; // this is to edit the iterating pointer to remomber or connect to the new structure pointer creaated so it
    // will form a linked list
}
void printthelist(struct node *head)
{
    if (head == NULL)
    {
        printf("the list is empty!\n");
        return; // we have to return it becuase if not it will excute the rest of the code if condition is true
    }
    struct node *ptr = head;
    printf("HEAD");
    while (ptr != NULL)
    { // we have to iterate till the last node where next element is null
        printf("->%d", ptr->data);
        ptr = ptr->next;
    }
    printf("->NULL\n");
}
int main()
{
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
    int choice;
    int n;
    printf("value you want to add: ");
    scanf("%d", &n);
    printf("enter your choice\n 1)add at front\n 2)add at end\n 3)add anywhere\n  : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Orginal list : \n");
        printthelist(head);
        printf("modified list : \n");
        addatfront(&head, n);
        printthelist(head);
        break;
    case 2:
        printf("Orginal list : \n");
        printthelist(head);
        printf("modified list : \n");
        addattheendofthelist(&head, n);
        printthelist(head);
        break;
    case 3:
        printf("Orginal list : \n");
        printthelist(head);
        int pos;
        printf("enter the position you want to add the number: ");
        scanf("%d", &pos);
        printf("modified list : \n");
        addatpos(&head,n,pos);
        printthelist(head);
        break;
    }
}