#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define SUBJECTS 3

// Structure to store student data
typedef struct {
    int rollNumber;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
} Student;

// Function prototypes
void addStudents(Student s[], int *count);
void calculateResults(Student *s);
void displayMarksheets(const Student s[], int count);
char determineGrade(float percentage);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n    MARKSHEET MANAGEMENT SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add Student Records");
        printf("\n2. Display All Marksheets");
        printf("\n3. Exit");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudents(students, &studentCount);
                break;
            case 2:
                displayMarksheets(students, studentCount);
                break;
            case 3:
                printf("\nExiting program. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to input student records
void addStudents(Student s[], int *count) {
    int num, i, j;
    printf("\nHow many students do you want to add? ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        if (*count >= MAX_STUDENTS) {
            printf("\nDatabase full! Cannot add more students.\n");
            return;
        }

        printf("\n--- Entering Details for Student %d ---\n", *count + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &s[*count].rollNumber);
        
        // Clear input buffer before reading string
        getchar(); 
        printf("Enter Full Name: ");
        fgets(s[*count].name, sizeof(s[*count].name), stdin);
        s[*count].name[strcspn(s[*count].name, "\n")] = '\0'; // Remove newline

        printf("Enter marks for %d subjects (out of 100):\n", SUBJECTS);
        for (j = 0; j < SUBJECTS; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%f", &s[*count].marks[j]);
        }

        calculateResults(&s[*count]);
        (*count)++;
    }
    printf("\nRecords added successfully!\n");
}

// Function to compute total, percentage, and grade
void calculateResults(Student *s) {
    s->total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        s->total += s->marks[i];
    }
    s->percentage = s->total / SUBJECTS;
    s->grade = determineGrade(s->percentage);
}

// Function to map percentage to letter grade
char determineGrade(float percentage) {
    if (percentage >= 85) return 'A';
    if (percentage >= 70) return 'B';
    if (percentage >= 50) return 'C';
    if (percentage >= 40) return 'D';
    return 'F';
}

// Function to print formatted marksheets
void displayMarksheets(const Student s[], int count) {
    if (count == 0) {
        printf("\nNo student records found! Please add records first.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n========================================");
        printf("\n               MARKSHEET                ");
        printf("\n========================================");
        printf("\nRoll No: %-10d Name: %s", s[i].rollNumber, s[i].name);
        printf("\n----------------------------------------");
        printf("\nSubject Scores:");
        for (int j = 0; j < SUBJECTS; j++) {
            printf("\n  Subject %d: %6.2f / 100", j + 1, s[i].marks[j]);
        }
        printf("\n----------------------------------------");
        printf("\nTotal Marks:   %6.2f", s[i].total);
        printf("\nPercentage:    %6.2f%%", s[i].percentage);
        printf("\nFinal Grade:   %c", s[i].grade);
        printf("\n========================================\n");
    }
}
return 0;
}