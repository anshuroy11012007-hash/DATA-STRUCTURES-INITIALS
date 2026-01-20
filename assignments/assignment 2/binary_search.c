#include <stdio.h>
int main()
{
    int i, j, temp, target;
    int n = 5; 
    int arr1[5] = {10, 15, 2, 6, 8};
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
    printf("Sorted array for Binary Search:\n");
    for(i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\n\nEnter element to search: ");
    scanf("%d", &target);
    int low = 0, high = n - 1, found = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr1[mid] == target) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        if (arr1[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }
    if (!found) printf("Element not found.\n");
    return 0;
}