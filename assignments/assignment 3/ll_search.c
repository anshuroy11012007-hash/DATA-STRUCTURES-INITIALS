#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
// Helper function to find the middle node between 'start' and 'last'
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

int main() {
    struct node *one, *two, *three, *head;
    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));
    head = one;
    one->data = 2; 
    one->next = two;
    two->data = 4; 
    two->next = three;
    three->data = 8; 
    three->next = NULL;
    printf("Enter element for Linear Search: ");    //linearear searching
    int lsearch;
    scanf("%d", &lsearch);
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == lsearch) {
            printf("Found %d via Linear Search at \n", lsearch);
            break;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL) printf("Not found.\n");

    printf("\nEnter element for Binary Search: ");  //binary searching
    int bsearch;
    scanf("%d", &bsearch);
    struct node* start = head;
    struct node* last = NULL;
    struct node* foundNode = NULL;
    do {
        struct node* mid = findMiddle(start, last);
        if (mid == NULL) break;
        if (mid->data == bsearch) {
            foundNode = mid;
            break;
        } 
        else if (mid->data < bsearch) {
            start = mid->next; // Search in the right half
        } 
        else {
            last = mid; // Search in the left half
        }
    } while (last == NULL || last != start);
    if (foundNode != NULL)
        printf("Element %d found via Binary Search!\n", bsearch);
    else
        printf("Element %d not found.\n", bsearch);

    free(one); free(two); free(three);  //free data
    return 0;
}