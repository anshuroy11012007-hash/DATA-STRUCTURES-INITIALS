#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Helper function to print the list to avoid repeating code
void printList(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d (Addr: %p, Prev: %p, Next: %p)\n", 
                ptr->data, (void*)ptr, (void*)ptr->prev, (void*)ptr->next);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    // 1. Initial Setup: Create 3 nodes (2 <-> 4 <-> 8)
    struct node* one = (struct node*)malloc(sizeof(struct node));
    struct node* two = (struct node*)malloc(sizeof(struct node));
    struct node* three = (struct node*)malloc(sizeof(struct node));
    
    one->data = 2; one->prev = NULL; one->next = two;
    two->data = 4; two->prev = one; two->next = three;
    three->data = 8; three->prev = two; three->next = NULL;
    
    struct node* head = one;

    printf("1. Original Doubly Linked List:\n");
    printList(head);

    // 2. Insertion at the END (Node with data 12)
    
    struct node* endNode = (struct node*)malloc(sizeof(struct node));
    endNode->data = 12;
    
    three->next = endNode;
    endNode->prev = three;
    endNode->next = NULL;

    printf("2. After Insertion at the End (12):\n");
    printList(head);

    // 3. Insertion at the START (Node with data 0)
    
    struct node* startNode = (struct node*)malloc(sizeof(struct node));
    startNode->data = 0;
    
    startNode->next = head;
    startNode->prev = NULL;
    head->prev = startNode;
    head = startNode; // Update head pointer

    printf("3. After Insertion at the Start (0):\n");
    printList(head);

    // 4. Insertion in the MIDDLE (Node with data 5 between 4 and 8)
    
    struct node* midNode = (struct node*)malloc(sizeof(struct node));
    midNode->data = 5;
    
    // We want to put 'midNode' between 'two' and 'three'
    midNode->next = three;
    midNode->prev = two;
    two->next = midNode;
    three->prev = midNode;

    printf("4. After Insertion in the Middle (5 between 4 and 8):\n");
    printList(head);

    // Free memory (Good practice)
    free(startNode); free(one); free(two); 
    free(midNode); free(three); free(endNode);

    return 0;
}
