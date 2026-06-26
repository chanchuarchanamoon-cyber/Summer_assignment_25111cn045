#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to store employee and salary details
typedef struct {
    int id;
    char name[50];
    char designation[30];
    double basic_salary;
    double allowance;
    double deduction;
    double net_salary;
} Employee;

// Function prototypes
void addEmployee(Employee emp[], int *count);
void displayPayroll(const Employee emp[], int count);
void calculateSalary(Employee *emp);

int main() {
    Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee & Calculate Salary");
        printf("\n2. Display Payroll Report");
        printf("\n3. Exit");
        printf("\nEnter your choice (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                addEmployee(employees, &employee_count);
                break;
            case 2:
                displayPayroll(employees, employee_count);
                break;
            case 3:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}

// Function to calculate net salary
void calculateSalary(Employee *emp) {
    emp->net_salary = emp->basic_salary + emp->allowance - emp->deduction;
}

// Function to add a new employee record
void addEmployee(Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: System database is full!\n");
        return;
    }

    Employee new_emp;
    
    printf("\nEnter Employee ID: ");
    scanf("%d", &new_emp.id);
    getchar(); // Clear newline character from buffer

    printf("Enter Employee Name: ");
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = '\0'; // Remove newline

    printf("Enter Designation: ");
    fgets(new_emp.designation, sizeof(new_emp.designation), stdin);
    new_emp.designation[strcspn(new_emp.designation, "\n")] = '\0';

    printf("Enter Basic Salary ($): ");
    scanf("%lf", &new_emp.basic_salary);

    printf("Enter Allowances ($): ");
    scanf("%lf", &new_emp.allowance);

    printf("Enter Deductions (Tax, PF, etc.) ($): ");
    scanf("%lf", &new_emp.deduction);

    // Compute net salary using helper function
    calculateSalary(&new_emp);

    // Save to array
    emp[*count] = new_emp;
    (*count)++;

    printf("\nRecord added successfully!\n");
}

// Function to display all employee pay slips
void displayPayroll(const Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n==================================================================================================\n");
    printf("%-5s | %-20s | %-15s | %-12s | %-10s | %-10s | %-12s\n", 
           "ID", "Name", "Designation", "Basic Sal.", "Allow.", "Deduct.", "Net Salary");
    printf("==================================================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d | %-20s | %-15s | %-12.2f | %-10.2f | %-10.2f | %-12.2f\n",
               emp[i].id, 
               emp[i].name, 
               emp[i].designation, 
               emp[i].basic_salary, 
               emp[i].allowance, 
               emp[i].deduction, 
               emp[i].net_salary);
    }
    printf("==================================================================================================\n");
}
return 0;
}