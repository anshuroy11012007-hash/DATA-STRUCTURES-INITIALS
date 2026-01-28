#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to traverse and print the Circular Linked List
void traverseList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* ptr = head;
    printf("Traversing CLL: ");

    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // The condition that stops the loop

    printf("(Head: %d)\n", head->data);
}

int main() {
    // 1. Manually creating a small Circular Linked List
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = head; // Pointing back to the start

    // 2. Calling the traversal function
    traverseList(head);

    return 0;
}
