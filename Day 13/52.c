int main() {
    int arr[] = {12, 35, 1, 10, 34, 1, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("Total even numbers: %d\n", even_count);
    printf("Total odd numbers: %d\n", odd_count);

    return 0;
}