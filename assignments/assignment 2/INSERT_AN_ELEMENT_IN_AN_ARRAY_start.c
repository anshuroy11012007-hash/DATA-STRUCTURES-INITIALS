#include <stdio.h>
int main()
{
    int i;
    int n = 5; 
    int arr1[6] = {10, 15, 2, 6, 8};
    printf("Original array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", arr1[i]);
    }
    printf("Enter the new element: ");
    int ele;
    scanf("%d", &ele);
    for(i = n - 1; i >= 0; i--)
    {
        arr1[i + 1] = arr1[i];
    }
    arr1[0] = ele;
    n++;
    printf("New array after insertion at beginning:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}