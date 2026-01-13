//WACP TO PRINT SUM OF 2 MATRICES//
#include<stdio.h>
int main()
{
    char arr1[2][2]={1,2,3,4};
    char arr2[2][2]={5,6,7,8};
    char sum[2][2];
    int i,j;
    for(i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
            sum[i][j]= arr1[i][j] + arr2[i][j];
            printf("%d ",sum[i][j]);
        }
    } 
    return 0;   
}