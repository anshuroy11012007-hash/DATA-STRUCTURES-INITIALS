#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
int main()
{
    struct node* head = NULL;
    struct node* one = NULL;
    struct node* two = NULL;
    struct node* three = NULL;
    struct node*four=NULL;
    one=(struct node*)malloc(sizeof(struct node));
    two=(struct node*)malloc(sizeof(struct node));
    three=(struct node*)malloc(sizeof(struct node));
    four=(struct node*)malloc(sizeof(struct node));
    head =one;
    one->prev=NULL;
    one->data=2;
    one->next=two;
    two->prev=one;
    two->data=4;
    two->next=three;
    three->prev=two;
    three->data=8;
    three->next=NULL;
    four -> data=12;
    //insertion in the end
    three -> next=four;
    four ->prev = three;
    four -> next =NULL;
    //insertion in start
    head = four;
    four -> prev = NULL;
    four -> next = one;
    //insertion in middle
    one -> next=four;
    four -> prev = one;
    four -> next = two;
    two -> prev = four;
    printf("The linked list is : \n");
    struct node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d is the data, %p is the address, %p is the previous address, %p is address of next node\n", ptr->data, ptr, ptr->prev, ptr->next);
        ptr = ptr->next;
    }
    return 0;
}