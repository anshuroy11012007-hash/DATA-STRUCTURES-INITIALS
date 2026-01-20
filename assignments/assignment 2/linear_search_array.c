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
   printf("\n\nEnter the element you want to search for: ");
   int searchItem,found;
    scanf("%d", &searchItem);
    for(i = 0; i < n; i++)
    {
        if(arr1[i] == searchItem)
        {
            printf("Element %d found at index %d.\n", searchItem, i);
            found = 1; 
            break;    
        }
    }
    if(found == 0)
    {
        printf("Element %d not found in the array.\n", searchItem);
    }
    return 0;
}