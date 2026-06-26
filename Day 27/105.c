#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

// Define the Student structure
typedef struct {
    int rollNumber;
    char name[50];
    float gpa;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                deleteStudent(students, &studentCount);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to add a new student record
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Database is full. Cannot add more students.\n");
        return;
    }

    Student newStudent;
    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    
    // Check if roll number already exists
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == newStudent.rollNumber) {
            printf("Error: A student with Roll Number %d already exists.\n", newStudent.rollNumber);
            return;
        }
    }

    printf("Enter Name: ");
    while (getchar() != '\n'); // Clear trailing newline from previous scanf
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove newline character

    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    students[*count] = newStudent;
    (*count)++;
    printf("Record added successfully!\n");
}

// Function to display all student records
void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-12s %-30s %-5s\n", "Roll Number", "Name", "GPA");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-12d %-30s %-.2f\n", students[i].rollNumber, students[i].name, students[i].gpa);
    }
}

// Function to search for a student by roll number
void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int searchRoll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == searchRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name       : %s\n", students[i].name);
            printf("GPA        : %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", searchRoll);
}

// Function to delete a student record
void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("\nNo student records available to delete.\n");
        return;
    }

    int deleteRoll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &deleteRoll);

    int foundIndex = -1;
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == deleteRoll) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Student with Roll Number %d not found.\n", deleteRoll);
        return;
    }

    // Shift subsequent elements left to fill the deleted slot
    for (int i = foundIndex; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Record deleted successfully!\n");
}
