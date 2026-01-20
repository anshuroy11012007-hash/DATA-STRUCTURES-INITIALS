#include <stdio.h>
int main()
{
    int i, pos, ele;
    int n = 5; 
    int arr1[10] = {10, 15, 2, 6, 8};
    printf("Original array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n\nEnter the position (index 0 to %d) for insertion: ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
    } else {
        printf("Enter the new element: ");
        scanf("%d", &ele);
        for(i = n - 1; i >= pos; i--)
        {
            arr1[i + 1] = arr1[i];
        }
        arr1[pos] = ele;
        n++;
        printf("New array:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }
    return 0;
}