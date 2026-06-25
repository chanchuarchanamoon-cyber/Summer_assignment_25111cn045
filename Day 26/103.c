#include <stdio.h>
#include <stdbool.h>
float account_balance = 5000.00; 
int user_pin = 1234;           

// Function prototypes
void display_menu();
void check_balance();
void deposit_money();
void withdraw_money();
bool authenticate_user();

int main() {
    int choice;
    printf("--- Welcome to the ATM Simulator ---\n");
    if (!authenticate_user()) {
        printf("\nToo many incorrect attempts. Exiting system.\n");
        return 0;
    }
    while (1) {
        display_menu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter numbers only.\n");
            break;
        }

        switch (choice) {
            case 1:
                check_balance();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }
    return 0;
}