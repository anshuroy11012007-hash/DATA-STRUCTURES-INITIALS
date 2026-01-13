//WACP TO REMOVE DUPLICATE ELEMENTS FROM A SORTED ARRAY//
//WACP TO FIND MAX AND MIN ELEMENTS IN AN ARRAY//
//WACP TO FIND 2ND LARGEST ELEMENTS IN AN ARRAY//
//WACP TO FIND SUM OF ALL ARRAY ELEMENTS//
//WACP TO PRINT FIBONACCI SERIES USING RECURSION//
//WACP TO PRINT SUM OF 2 MATRICES//
//WACP FOR PASSING AN ARRAY TO A FUNC. AND PRINT AVERAGE//
//WACP TO FIND LARGEST OF 3 NUM. USING TERNARY OPERATOR//
//WACP TO CHECK FOR PALLINDROME AND IF IT IS THEN PRINT HALF OF IT//

#include<stdio.h>
int main()
{
    char arr1[]={0,0,0,1,1,1,1,2,2,3,3,3,5,5,5,6,8,9,9,9,9};
    int i;
    int n = sizeof(arr1) / sizeof(arr1[0]);
    for (i=0;i<n;i++)
    {
        if(i>0 && arr1[i]==arr1[i-1])
        {
            continue;
        }
        else
        {
            printf("%d ",arr1[i]);
        }
        
    }
    return 0;
}
