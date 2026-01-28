#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Function to print the list
void printList(struct node* head) {
    struct node* ptr = head;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    // Setting up an initial list: 10 <-> 20 <-> 30 <-> 40 <-> 50
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    struct node *n3 = (struct node*)malloc(sizeof(struct node));
    struct node *n4 = (struct node*)malloc(sizeof(struct node));
    struct node *n5 = (struct node*)malloc(sizeof(struct node));

    n1->data = 10; n1->prev = NULL; n1->next = n2;
    n2->data = 20; n2->prev = n1;   n2->next = n3;
    n3->data = 30; n3->prev = n2;   n3->next = n4;
    n4->data = 40; n4->prev = n3;   n4->next = n5;
    n5->data = 50; n5->prev = n4;   n5->next = NULL;

    struct node* head = n1;

    printf("1. Initial Doubly Linked List:\n");
    printList(head);

    // --- DELETION AT THE START (Remove 10) ---
    // 
    struct node* tempStart = head;
    head = head->next;     // Move head to the second node
    if (head != NULL) {
        head->prev = NULL; // Disconnect the old head
    }
    free(tempStart);

    printf("2. After Deletion at the Start (Removed 10):\n");
    printList(head);

    // --- DELETION AT THE END (Remove 50) ---
    // 
    struct node* tempEnd = head;
    while (tempEnd->next != NULL) {
        tempEnd = tempEnd->next; // Traverse to the last node
    }
    tempEnd->prev->next = NULL; // Set the second-to-last node's next to NULL
    free(tempEnd);

    printf("3. After Deletion at the End (Removed 50):\n");
    printList(head);

    // --- DELETION IN THE MIDDLE (Remove 30) ---
    // 
    // To remove n3 (30), we must connect n2 (20) and n4 (40) together.
    struct node* tempMid = n3; 
    n2->next = n4;             // n2 points forward to n4
    if (n4 != NULL) {
        n4->prev = n2;         // n4 points backward to n2
    }
    free(tempMid);

    printf("4. After Deletion in the Middle (Removed 30):\n");
    printList(head);

    return 0;
}
