#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
int main()
{
    struct node* head = NULL;
    struct node* one = NULL;
    struct node* two = NULL;
    struct node* three = NULL;
    struct node* four = NULL;
    one=(struct node*)malloc(sizeof(struct node));
    two=(struct node*)malloc(sizeof(struct node));
    three=(struct node*)malloc(sizeof(struct node));
    four=(struct node*)malloc(sizeof(struct node));
    head =one;
    one->data=2;
    one->next=two;
    two->data=8;
    two->next=three;
    three->data=9453;
    three->next=NULL;
    printf("The initial linked list is : \n");
    struct node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    three->next=four;   
    four->data=39;  
    four->next=NULL;
    printf("The linked list after insertion at the end is : \n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}