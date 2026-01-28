#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// --- LINEAR SEARCH ---
// Simply walks through every node
struct node* linearSearch(struct node* head, int target) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) return temp;
        temp = temp->next;
    }
    return NULL;
}

// --- HELPER: FIND MIDDLE ---
// Necessary for Binary Search logic
struct node* findMiddle(struct node* start, struct node* last) {
    if (start == NULL) return NULL;
    
    struct node* slow = start;
    struct node* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// --- BINARY SEARCH ---
struct node* binarySearch(struct node* head, int target) {
    struct node* start = head;
    struct node* last = NULL; // NULL represents the end of the list

    do {
        struct node* mid = findMiddle(start, last);
        if (mid == NULL) return NULL;

        if (mid->data == target) return mid;
        else if (mid->data < target) {
            start = mid->next; // Search in right half
        } else {
            last = mid; // Search in left half
        }
    } while (last == NULL || last != start);

    return NULL;
}

// Helper to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

int main() {
    // Create a sorted DLL: 10 <-> 20 <-> 30 <-> 40 <-> 50
    struct node* head = createNode(10);
    head->next = createNode(20); head->next->prev = head;
    head->next->next = createNode(30); head->next->next->prev = head->next;
    head->next->next->next = createNode(40); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(50); head->next->next->next->next->prev = head->next->next->next;

    int keyl = 40;
    int keyb = 30;

    // Linear Search
    //[Image of linear search in a linked list]
    struct node* resL = linearSearch(head, keyl);
    if(resL) printf("Linear Search: Found %d at address %p\n", keyl, (void*)resL);

    // Binary Search
    //[Image of binary search logic on a linked list]
    struct node* resB = binarySearch(head, keyb);
    if(resB) printf("Binary Search: Found %d at address %p\n", keyb, (void*)resB);

    return 0;
}
