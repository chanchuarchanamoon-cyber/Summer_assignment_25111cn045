include <stdio.h>
void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0
    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        binaryNum[i] = n % 2; // Store remainder (0 or 1)
        n = n / 2;            // Get the quotient for the next iteration
        i++;                  // Move to the next array index
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

int main() {
    int decimal;

    // Prompt the user for input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Validate if the input is a positive number or zero
    if (decimal < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        printf("Binary equivalent: ");
        decimalToBinary(decimal); // Call the custom function
        printf("\n");
    }

    return 0;
}