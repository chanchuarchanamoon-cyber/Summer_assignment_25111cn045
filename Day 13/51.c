#include <stdio.h>
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]); 

    // Loop through and print each element
    for (int i = 0; i < length; i++) {
        sum=sum + arr[i];
        avergae= sum/length;
}
printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}