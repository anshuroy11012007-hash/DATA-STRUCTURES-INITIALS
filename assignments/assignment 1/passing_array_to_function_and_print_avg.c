#include <stdio.h>
float findAverage(int arr[], int size);
int main() {
    int n, i;
    int numbers[100];
    float avg;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    avg = findAverage(numbers, n);
    printf("The average of the array is: %.2f\n", avg);
    return 0;
}
float findAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}