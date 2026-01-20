//WACP TO INSERT AN ELEMENT IN AN ARRAY
    //AT THE END
    //AT THE START
    //IN BETWEEN
//WACP TO DELETE AN ARRAY ELEMENT
//WACP TO TRAVERSE AN ARRAY
//WACP TO PERFORM LINEAR SEARCH
//WACP TO PERFORM BINARY SEARCH
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
    arr1[n] = ele;
    n++;
    printf("New array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", arr1[i]);
    }
    return 0;
}