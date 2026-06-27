#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

// Structure to store book information
typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

// Global array to store library database
Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void displayMenu();
void addBook();
void viewBooks();
void searchBook();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        getchar(); // Clear the newline character from buffer

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nExiting Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n=============================");
    printf("\n  LIBRARY MANAGEMENT SYSTEM  ");
    printf("\n=============================");
    printf("\n1. Add New Book");
    printf("\n2. View All Books");
    printf("\n3. Search for a Book");
    printf("\n4. Exit");
    printf("\n=============================\n");
}

// Function to add a book to the library
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nError: Library database is full!\n");
        return;
    }

    Book newBook;
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &newBook.id);
    getchar(); // Clear newline

    // Validate if ID already exists
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("Error: A book with ID %d already exists!\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline

    printf("Enter Author Name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline

    printf("Enter Publication Year: ");
    scanf("%d", &newBook.year);

    library[bookCount] = newBook;
    bookCount++;

    printf("\nBook added successfully!\n");
}

// Function to display all books
void viewBooks() {
    if (bookCount == 0) {
        printf("\nThe library is currently empty.\n");
        return;
    }

    printf("\n-------------------------------------------------------------------\n");
    printf("%-10s %-25s %-20s %-10s\n", "Book ID", "Title", "Author", "Year");
    printf("-------------------------------------------------------------------\n");
    
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-25s %-20s %-10d\n", 
               library[i].id, library[i].title, library[i].author, library[i].year);
    }
    printf("-------------------------------------------------------------------\n");
}

// Function to search for a book by title
void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library is empty. Nothing to search.\n");
        return;
    }

    char searchTitle[TITLE_LEN];
    int found = 0;

    printf("\nEnter the title of the book to search: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline

    printf("\nSearch Results:\n");
    for (int i = 0; i < bookCount; i++) {
        // Case-sensitive comparison
        if (strstr(library[i].title, searchTitle) != NULL) {
            if (!found) {
                printf("-------------------------------------------------------------------\n");
                printf("%-10s %-25s %-20s %-10s\n", "Book ID", "Title", "Author", "Year");
                printf("-------------------------------------------------------------------\n");
            }
            printf("%-10d %-25s %-20s %-10d\n", 
                   library[i].id, library[i].title, library[i].author, library[i].year);
            found = 1;
        }
    }

    if (found) {
        printf("-------------------------------------------------------------------\n");
    } else {
        printf("No books found matching the title \"%s\".\n", searchTitle);
    }
}
return 0;
}