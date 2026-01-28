#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// --- LINEAR SEARCH ---
struct node* linearSearch(struct node* head, int target) {
    if (head == NULL) return NULL;
    
    struct node* temp = head;
    do {
        if (temp->data == target) return temp;
        temp = temp->next;
    } while (temp != head); // Stop when we return to head
    
    return NULL;
}

// --- HELPER: FIND MIDDLE ---
struct node* findMiddle(struct node* start, struct node* last) {
    if (start == NULL) return NULL;
    
    struct node* slow = start;
    struct node* fast = start->next;

    // In CLL, we stop if we hit the 'last' boundary 
    // or if fast/fast->next completes the circle back to 'start'
    while (fast != last && fast->next != last) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// --- BINARY SEARCH ---
struct node* binarySearch(struct node* head, int target) {
    if (head == NULL) return NULL;

    struct node* start = head;
    struct node* last = head; 
    
    // First, we must find the actual 'end' of the circular list
    // to act as our initial 'last' boundary
    while (last->next != head) {
        last = last->next;
    }
    struct node* tail = last; 
    last = head; // In this logic, 'last' boundary is the head (the loop point)

    do {
        struct node* mid = findMiddle(start, last);
        if (mid == NULL) return NULL;

        if (mid->data == target) return mid;
        else if (mid->data < target) {
            start = mid->next;
        } else {
            last = mid;
        }
        
        // If start moves past the tail or reaches the last boundary, break
        if (start == head) break; 
        
    } while (start != last);

    return NULL;
}

// Helper to create a new node and link it circularly
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL; 
    return newNode;
}

int main() {
    // Creating a sorted CLL: 10 -> 20 -> 30 -> 40 -> 50 -> (back to 10)
    struct node* n1 = createNode(10);
    struct node* n2 = createNode(20);
    struct node* n3 = createNode(30);
    struct node* n4 = createNode(40);
    struct node* n5 = createNode(50);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1; // Circular link

    struct node* head = n1;
    int keyl = 40;
    int keyb = 30;

    

    // Linear Search
    struct node* resL = linearSearch(head, keyl);
    if(resL) printf("Linear Search: Found %d at address %p\n", keyl, (void*)resL);
    else printf("Linear Search: %d not found\n", keyl);

    // Binary Search
    struct node* resB = binarySearch(head, keyb);
    if(resB) printf("Binary Search: Found %d at address %p\n", keyb, (void*)resB);
    else printf("Binary Search: %d not found\n", keyb);

    return 0;
}
