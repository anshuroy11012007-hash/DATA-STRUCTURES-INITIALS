#include <stdio.h>
int fib(int num) 
{
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    else 
    {
        return fib(num - 1) + fib(num - 2);
    }
}
int main() {
    int n, i;
    printf("please enter the number of terms you want to see:\n");
    scanf("%d", &n);
    if (n < 0) {
        printf("ERROR");
    } else 
    {
        printf("The Fibonacci series up to %d terms is:\n", n);
        
        for (i = 0; i < n; i++) 
        {
            printf("%d, ", fib(i));
        }
        printf("\n");
    }
    return 0;
}