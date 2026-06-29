#include <stdio.h>

int main() {
    int arr[100], n, i;
    int sum = 0, expectedSum, missing;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter %d numbers (one number missing):\n", n - 1);
    for(i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    expectedSum = n * (n + 1) / 2;
    missing = expectedSum - sum;

    printf("Missing number = %d\n", missing);

    return 0;
}