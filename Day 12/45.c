#include <stdio.h>

// Function prototype
int isPalindrome(int num);

int main() {
    int number;

    // Input from user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Call function and check the return value
    if (isPalindrome(number)) {
        printf("%d is a palindrome number.\n", number);
    } else {
        printf("%d is not a palindrome number.\n", number);
    }

    return 0;
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;
    int remainder;

    // Reverse the number
    while (num > 0) {
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder;
        num = num / 10;
    }

    // Check if original and reversed numbers are equal
    if (originalNum == reversedNum) {
        return 1; // It is a palindrome
    } else {
        return 0; // It is not a palindrome
    }
}