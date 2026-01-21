//WACP TO CREATE A LL
//WACP TO INSERT AN ELEMENT 
    //AT THE BEGINNING
    //AT THE END
    //IN THE MIDDLE
//WACP TO DELETE AN ELEMENT
    //AT THE BEGINNING
    //AT THE END
    //IN THE MIDDLE
//WACP TO TRAVERSE A SINGLE LINKED LIST
//WACP TO SEARCH AN ELEMENT IN A SINGLE LL USING LINEAR AND BINARY SEARCH
//WACP TO CREATE A DOUBLE LL HAVING 3 NODES
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
    one=(struct node*)malloc(sizeof(struct node));
    two=(struct node*)malloc(sizeof(struct node));
    three=(struct node*)malloc(sizeof(struct node));
    head =one;
    one->data=2;
    one->next=two;
    two->data=8;
    two->next=three;
    three->data=9453;
    three->next=NULL;
    printf("The linked list is : \n");
    struct node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}