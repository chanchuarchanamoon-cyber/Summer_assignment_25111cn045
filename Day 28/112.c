#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "contacts.dat"

// Define the Contact structure
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

// Function prototypes
void addContact();
void listContacts();
void searchContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to add a contact to the binary file
void addContact() {
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact c;
    printf("\nEnter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);

    printf("Contact added successfully!\n");
}

// Function to read and display all contacts
void listContacts() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts found. Add some contacts first!\n");
        return;
    }

    Contact c;
    int count = 1;
    printf("\n%-5s %-20s %-15s %-25s\n", "S.N.", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------\n");

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        printf("%-5d %-20s %-15s %-25s\n", count++, c.name, c.phone, c.email);
    }

    fclose(fp);
}

// Function to search for a contact by name
void searchContact() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    char searchName[50];
    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        if (strcasecmp(c.name, searchName) == 0) { // Case-insensitive comparison
            if (!found) {
                printf("\nContact found:\n");
                printf("-------------------------\n");
            }
            printf("Name:  %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            printf("-------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(fp);
}

// Function to delete a contact by name
void deleteContact() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    char deleteName[50];
    printf("\nEnter the name of the contact to delete: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    // Create a temporary file to store records we want to keep
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    Contact c;
    int found = 0;

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        if (strcasecmp(c.name, deleteName) == 0) {
            found = 1; // Skip writing this record to temp file
        } else {
            fwrite(&c, sizeof(Contact), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILENAME);        // Delete original file
        rename("temp.dat", FILENAME); // Rename temp file to original
        printf("Contact deleted successfully.\n");
    } else {
        remove("temp.dat"); // Clean up temp file if nothing changed
        printf("Contact not found.\n");
    }
}

// Helper function to flush standard input stream
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
return 0;
}