#include <stdio.h>

int main() {
    int arr[100], n, num, i, count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number whose frequency is to be found: ");
    scanf("%d", &num);

    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            count++;
        }
    }

    printf("Frequency of %d = %d\n", num, count);

    return 0;
}