//WAP TO FIND SUM OF ALL ARRAY ELEMENTS//
#include<stdio.h>
int main()
{
    char arr1[]={1,2,3,4,5,6,7,8,9,1,2,3,4,5};
    int sum=0;
    int i;
    int l=strlen(arr1);
    for(i=0;i<l;i++)
    {
        sum= sum + arr1[i];
    }
    
        printf("%d",sum);
    
    return 0;
}