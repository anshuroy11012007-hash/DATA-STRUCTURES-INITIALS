#include <stdio.h>
int main()
{
    int i,pos;
    int n = 5; 
    int arr1[6] = {10, 15, 2, 6, 8};
    printf("Original array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", arr1[i]);
    }
    printf("\n\nEnter the index to delete (0 to %d): ", n-1);
    scanf("%d", &pos);
    if (pos >= n || pos < 0) {
        printf("Invalid position!\n");
    } else {
        for(i = pos; i < n - 1; i++)
        {
            arr1[i] = arr1[i + 1];
        }
        n--;
        printf("Array after deletion:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }
    return 0;
}