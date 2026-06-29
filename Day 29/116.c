#include <stdio.h>

int main() {
    int id[100], qty[100];
    float price[100];
    int n = 0, choice, i, searchId;

    do {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter Product ID: ");
                scanf("%d", &id[n]);

                printf("Enter Quantity: ");
                scanf("%d", &qty[n]);

                printf("Enter Price: ");
                scanf("%f", &price[n]);

                n++;
                printf("Product added successfully!\n");
                break;

            case 2:
                if(n == 0) {
                    printf("No products available.\n");
                } else {
                    printf("\nID\tQuantity\tPrice\n");
                    for(i = 0; i < n; i++) {
                        printf("%d\t%d\t\t%.2f\n",
                               id[i], qty[i], price[i]);
                    }
                }
                break;

            case 3:
                printf("Enter Product ID to search: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(id[i] == searchId) {
                        printf("Product Found!\n");
                        printf("ID: %d\n", id[i]);
                        printf("Quantity: %d\n", qty[i]);
                        printf("Price: %.2f\n", price[i]);
                        break;
                    }
                }

                if(i == n)
                    printf("Product not found!\n");
                break;

            case 4:
                printf("Enter Product ID: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(id[i] == searchId) {
                        printf("Enter New Quantity: ");
                        scanf("%d", &qty[i]);
                        printf("Quantity updated successfully!\n");
                        break;
                    }
                }

                if(i == n)
                    printf("Product not found!\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}