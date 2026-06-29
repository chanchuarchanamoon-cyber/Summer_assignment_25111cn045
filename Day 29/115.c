#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int choice;

    printf("Enter first string: ");
    gets(str1);

    do {
        printf("\n===== STRING OPERATIONS =====\n");
        printf("1. Find Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse String\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        switch(choice) {
            case 1:
                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                strcpy(str2, str1);
                printf("Copied String: %s\n", str2);
                break;

            case 3:
                printf("Enter second string: ");
                gets(str2);
                strcat(str1, str2);
                printf("Concatenated String: %s\n", str1);
                break;

            case 4:
                printf("Enter second string: ");
                gets(str2);

                if(strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 5:
                strcpy(str2, str1);
                strrev(str2);   // Works in some compilers
                printf("Reversed String: %s\n", str2);
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