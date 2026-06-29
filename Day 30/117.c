#include <stdio.h>
#include <string.h>

int main() {
    int roll[100], marks[100];
    char name[100][50];
    int n = 0, choice, i, searchRoll;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Marks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll[n]);

                printf("Enter Name: ");
                scanf(" %[^\n]", name[n]);

                printf("Enter Marks: ");
                scanf("%d", &marks[n]);

                n++;
                printf("Student record added successfully!\n");
                break;

            case 2:
                if(n == 0) {
                    printf("No records found!\n");
                } else {
                    printf("\nRoll No\tName\t\tMarks\n");
                    for(i = 0; i < n; i++) {
                        printf("%d\t%s\t\t%d\n",
                               roll[i], name[i], marks[i]);
                    }
                }
                break;

            case 3:
                printf("Enter Roll Number to Search: ");
                scanf("%d", &searchRoll);

                for(i = 0; i < n; i++) {
                    if(roll[i] == searchRoll) {
                        printf("\nStudent Found!\n");
                        printf("Roll No: %d\n", roll[i]);
                        printf("Name: %s\n", name[i]);
                        printf("Marks: %d\n", marks[i]);
                        break;
                    }
                }

                if(i == n)
                    printf("Student not found!\n");
                break;

            case 4:
                printf("Enter Roll Number: ");
                scanf("%d", &searchRoll);

                for(i = 0; i < n; i++) {
                    if(roll[i] == searchRoll) {
                        printf("Enter New Marks: ");
                        scanf("%d", &marks[i]);
                        printf("Marks updated successfully!\n");
                        break;
                    }
                }

                if(i == n)
                    printf("Student not found!\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}
Operations