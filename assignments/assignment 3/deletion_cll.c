#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* tail = NULL;

// Helper to print the list
void printList() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = tail->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(Head)\n\n");
}

// 1. DELETE FROM START
void deleteStart() {
    if (tail == NULL) return;

    struct node* head = tail->next;
    if (head == tail) { // Only one node in list
        free(head);
        tail = NULL;
    } else {
        tail->next = head->next; // Tail bypasses old head
        free(head);
    }
    printf("After deleting from Start:\n");
    printList();
}

// 2. DELETE FROM END
void deleteEnd() {
    if (tail == NULL) return;

    struct node* head = tail->next;
    if (head == tail) { // Only one node
        free(head);
        tail = NULL;
    } else {
        struct node* temp = head;
        // Traverse to find the node before tail
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head; // New end points to head
        free(tail);
        tail = temp; // Update tail pointer
    }
    printf("After deleting from End:\n");
    printList();
}

// 3. DELETE A SPECIFIC NODE (Middle)
void deleteNode(int key) {
    if (tail == NULL) return;

    struct node *curr = tail->next, *prev = tail;
    
    // Search for the node
    do {
        if (curr->data == key) {
            if (curr == tail->next) {
                deleteStart();
                return;
            }
            if (curr == tail) {
                deleteEnd();
                return;
            }
            prev->next = curr->next; // Bypass the node
            free(curr);
            printf("After deleting node %d:\n", key);
            printList();
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    
    printf("Node %d not found.\n", key);
}

// Function to add nodes for the demo
void insert(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

int main() {
    insert(10); insert(20); insert(30); insert(40); insert(50);
    printf("Original List:\n");
    printList();

    
    deleteStart();

    
    deleteEnd();

    
    deleteNode(30);

    return 0;
}
