#include <stdio.h>

int main() {
    long long binary_num;
    int decimal_num = 0, base = 1, remainder;
    printf("Enter a binary number (composed of 0s and 1s): ");
    scanf("%lld", &binary_num);

    long long temp = binary_num;}

    while (temp > 0) {
        remainder = temp % 10;       // Extract the rightmost digit
        decimal_num += remainder * base; // Multiply by current power of 2 and add to sum
        temp = temp / 10;            // Remove the rightmost digi
        base = base * 2;             // Increase the power of 2 for the next position
    }

    printf("%lld in binary = %d in decimal\n", binary_num, decimal_num);

    return 0;