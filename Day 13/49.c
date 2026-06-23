#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]); 

    // Loop through and print each element
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}