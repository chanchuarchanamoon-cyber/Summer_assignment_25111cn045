#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int remainder;
    int digits = 0;
    int result = 0;

    // Find the number of digits
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    // Calculate the sum of power of digits
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        // Use round to prevent floating-point inaccuracies from pow()
        result += round(pow(remainder, digits));
        temp /= 10;
    }

    return (result == originalNum);
}

int main() {
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}