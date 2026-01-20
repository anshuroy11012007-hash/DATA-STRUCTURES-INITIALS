#include <stdio.h>
int main()
{
    int i;
    int n = 5; 
    int arr1[6] = {10, 15, 2, 6, 8};
    printf("Traversing the array to print elements:\n");
    for(i = 0; i < n; i++)
    {
        printf("Element at index %d: %d\n", i, arr1[i]);
    }
    printf("\nTraversal complete.");
    return 0;
}