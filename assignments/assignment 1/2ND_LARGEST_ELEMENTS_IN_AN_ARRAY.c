#include <stdio.h>
#include <limits.h> 
int main() {
    int arr[100], n, i;
    int max, secondMax;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Array needs at least two elements.\n");
        return 0;
    }
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = secondMax = INT_MIN;
    for (i = 0; i < n; i++) {
        if (arr[i] > max) 
        {
            secondMax = max;
            max = arr[i];
        } 
        else if (arr[i] > secondMax && arr[i] < max)
        {
            secondMax = arr[i];
        }
    }
    if (secondMax == INT_MIN) {
        printf("There is no second largest element (all elements might be the same).\n");
    } else {
        printf("The second largest element is: %d\n", secondMax);
    }
    return 0;
}