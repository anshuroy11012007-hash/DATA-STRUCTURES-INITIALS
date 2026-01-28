#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a CLL with 3 nodes
struct node* createCircularList() {
    struct node *first, *second, *third;

    // Allocate memory
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Initialize first node
    first->data = 10;
    first->next = second;

    // Initialize second node
    second->data = 20;
    second->next = third;

    // Initialize third node
    third->data = 30;
    third->next = first; // Point back to first (The Circular Link)

    return first; // Returning head
}

// Function to traverse and print the CLL
void printList(struct node* head) {
    struct node* temp = head;

    if (head != NULL) {
        printf("Circular Linked List: ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head); // Stop when we come back to head
        printf("(Back to Head)\n");
    }
}

int main() {
    struct node* head = createCircularList();
    
   // [Image of circular linked list structure]
    
    printList(head);

    return 0;
}
