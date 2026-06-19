#include <stdio.h>

int main() {
    int size, i, j;
    int main_sum = 0, secondary_sum = 0;

    
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int matrix[size][size];

    
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (i = 0; i < size; i++) {
        main_sum += matrix[i][i];                 
        secondary_sum += matrix[i][size - i - 1]; 
    }

    
    printf("\nThe given matrix is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    
    printf("Sum of Main Diagonal elements: %d", main_sum);
    printf("Sum of Secondary Diagonal elements: %d", secondary_sum);

    return 0;
}