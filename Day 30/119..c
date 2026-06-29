#include <stdio.h>
#include <string.h>

int main() {
    int empId[100], age[100];
    float salary[100];
    char name[100][50];
    int n = 0, choice, searchId, i;

    do {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &empId[n]);

                printf("Enter Employee Name: ");
                scanf(" %[^\n]", name[n]);

                printf("Enter Age: ");
                scanf("%d", &age[n]);

                printf("Enter Salary: ");
                scanf("%f", &salary[n]);

                n++;
                printf("Employee added successfully!\n");
                break;

            case 2:
                if(n == 0) {
                    printf("No employee records found!\n");
                } else {
                    printf("\nID\tName\t\tAge\tSalary\n");
                    for(i = 0; i < n; i++) {
                        printf("%d\t%s\t\t%d\t%.2f\n",
                               empId[i], name[i], age[i], salary[i]);
                    }
                }
                break;

            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(empId[i] == searchId) {
                        printf("\nEmployee Found!\n");
                        printf("ID: %d\n", empId[i]);
                        printf("Name: %s\n", name[i]);
                        printf("Age: %d\n", age[i]);
                        printf("Salary: %.2f\n", salary[i]);
                        break;
                    }
                }

                if(i == n)
                    printf("Employee not found!\n");
                break;

            case 4:
                printf("Enter Employee ID: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(empId[i] == searchId) {
                        printf("Enter New Salary: ");
                        scanf("%f", &salary[i]);
                        printf("Salary updated successfully!\n");
                        break;
                    }
                }

                if(i == n)
                    printf("Employee not found!\n");
                break;

            case 5:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(empId[i] == searchId) {
                        int j;
                        for(j = i; j < n - 1; j++) {
                            empId[j] = empId[j + 1];
                            age[j] = age[j + 1];
                            salary[j] = salary[j + 1];
                            strcpy(name[j], name[j + 1]);
                        }
                        n--;
                        printf("Employee deleted successfully!\n");
                        break;
                    }
                }

                if(i == n)
                    printf("Employee not found!\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}