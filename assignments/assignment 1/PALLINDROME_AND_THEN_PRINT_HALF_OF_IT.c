#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int i, len, isPalindrome = 1;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalindrome = 0; 
            break;
        }
    }
    if (isPalindrome) {
        printf("The string is a Palindrome.\n");
        printf("Half of the string is: ");
        for (i = 0; i < len / 2; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    } else {
        printf("The string is NOT a Palindrome.\n");
    }
    return 0;
}