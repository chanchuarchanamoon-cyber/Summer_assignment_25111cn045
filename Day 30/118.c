#include <stdio.h>
#include <string.h>

int main() {
    int bookId[100], n = 0, choice, searchId, i;
    char title[100][50];

    do {
        printf("\n===== MINI LIBRARY SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &bookId[n]);

                printf("Enter Book Title: ");
                scanf(" %[^\n]", title[n]);

                n++;
                printf("Book added successfully!\n");
                break;

            case 2:
                if(n == 0) {
                    printf("No books available.\n");
                } else {
                    printf("\nBook ID\tBook Title\n");
                    for(i = 0; i < n; i++) {
                        printf("%d\t%s\n", bookId[i], title[i]);
                    }
                }
                break;

            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(bookId[i] == searchId) {
                        printf("Book Found!\n");
                        printf("ID: %d\n", bookId[i]);
                        printf("Title: %s\n", title[i]);
                        break;
                    }
                }

                if(i == n)
                    printf("Book not found!\n");
                break;

            case 4:
                printf("Enter Book ID to delete: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(bookId[i] == searchId) {
                        int j;
                        for(j = i; j < n - 1; j++) {
                            bookId[j] = bookId[j + 1];
                            strcpy(title[j], title[j + 1]);
                        }
                        n--;
                        printf("Book deleted successfully!\n");
                        break;
                    }
                }

                if(i == n)
                    printf("Book not found!\n");
                break;

            case 5:
                printf("Exiting Library System...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}