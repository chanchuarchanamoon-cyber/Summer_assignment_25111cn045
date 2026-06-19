#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int mat[r][c], trans[c][r];

    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
            trans[j][i] = mat[i][j]; 
        }
    }

    
    printf("\nTranspose Matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) printf("%d ", trans[i][j]);
        printf("\n");
    }
    return 0;
}