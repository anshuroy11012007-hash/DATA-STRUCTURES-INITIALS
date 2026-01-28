#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Global tail pointer for easier management
struct node* tail = NULL;

void printList() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = tail->next; // Start from head
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(Head)\n\n");
}

// 1. INSERT AT START
void insertAtStart(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = tail->next; // Point to current head
        tail->next = newNode;       // Tail points to new head
    }
    printf("Inserted %d at Start:\n", val);
}

// 2. INSERT AT END
void insertAtEnd(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = tail->next; // New node points to head
        tail->next = newNode;       // Old tail points to new node
        tail = newNode;             // Update tail pointer to the new end
    }
    printf("Inserted %d at End:\n", val);
}

// 3. INSERT AT MIDDLE (After a specific value)
void insertAtMiddle(int val, int afterVal) {
    if (tail == NULL) return;

    struct node* temp = tail->next;
    do {
        if (temp->data == afterVal) {
            struct node* newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == tail) tail = newNode; // If inserted after tail, update tail
            printf("Inserted %d after %d:\n", val, afterVal);
            return;
        }
        temp = temp->next;
    } while (temp != tail->next);
    printf("Value %d not found in list.\n", afterVal);
}

int main() {
    // Initializing list
    insertAtStart(20);
    insertAtStart(10);
    printList();

    

    insertAtEnd(30);
    printList();

    

    insertAtMiddle(25, 20); // Insert 25 after 20
    printList();

    

    return 0;
}
