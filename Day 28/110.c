#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to store account details
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account bank[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
int findAccount(int accNum);

int main() {
    int choice;

    while (1) {
        printf("\n=== BANK MANAGEMENT SYSTEM ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: printf("Thank you for using our banking system!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to create a new account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Bank system is full! Cannot add more accounts.\n");
        return;
    }

    Account newAcc;
    printf("\nEnter Account Number: ");
    scanf("%d", &newAcc.accountNumber);

    // Check if account number already exists
    if (findAccount(newAcc.accountNumber) != -1) {
        printf("Error: Account number already exists!\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    getchar(); // Clear newline character from buffer
    fgets(newAcc.name, sizeof(newAcc.name), stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Initial Deposit: $");
    scanf("%f", &newAcc.balance);

    if (newAcc.balance < 0) {
        printf("Initial deposit cannot be negative!\n");
        return;
    }

    bank[totalAccounts] = newAcc;
    totalAccounts++;
    printf("Account created successfully!\n");
}

// Function to deposit money
void deposit() {
    int accNum, index;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(accNum);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Amount to Deposit: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Must be greater than 0.\n");
        return;
    }

    bank[index].balance += amount;
    printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, bank[index].balance);
}

// Function to withdraw money
void withdraw() {
    int accNum, index;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(accNum);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Amount to Withdraw: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    if (amount > bank[index].balance) {
        printf("Insufficient balance! Current Balance: $%.2f\n", bank[index].balance);
        return;
    }

    bank[index].balance -= amount;
    printf("Successfully withdrew $%.2f. New Balance: $%.2f\n", amount, bank[index].balance);
}

// Function to display balance
void checkBalance() {
    int accNum, index;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(accNum);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", bank[index].accountNumber);
    printf("Holder Name   : %s\n", bank[index].name);
    printf("Current Balance: $%.2f\n", bank[index].balance);
}

// Helper function to search for an account index by account number
int findAccount(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            return i; // Return array index
        }
    }
    return 0; // Not found
}
