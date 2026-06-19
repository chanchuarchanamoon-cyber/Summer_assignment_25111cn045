int main() {
    int number;
    unsigned long long fact;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Error! Factorial of a negative number does not exist.\n");
    } else {
        fact = calculateFactorial(number);
        printf("Factorial of %d = %llu\n", number, fact);
    }

    return 0;
}