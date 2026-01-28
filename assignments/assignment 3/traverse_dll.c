#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// --- FORWARD TRAVERSAL ---
void traverseForward(struct node* head) {
    struct node* ptr = head;
    printf("Forward Traversal:  ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next; // Move to the next node
    }
    printf("NULL\n");
}

// --- BACKWARD TRAVERSAL ---
void traverseBackward(struct node* tail) {
    struct node* ptr = tail;
    printf("Backward Traversal: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->prev; // Move to the previous node
    }
    printf("NULL\n");
}

int main() {
    // Creating nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* tail = (struct node*)malloc(sizeof(struct node));

    // Linking 10 <-> 20 <-> 30
    head->data = 10; head->prev = NULL; head->next = second;
    second->data = 20; second->prev = head; second->next = tail;
    tail->data = 30; tail->prev = second; tail->next = NULL;

    //[Image of doubly linked list traversal diagram]

    // Execute traversals
    traverseForward(head);
    traverseBackward(tail);

    // Clean up memory
    free(head);
    free(second);
    free(tail);

    return 0;
}
