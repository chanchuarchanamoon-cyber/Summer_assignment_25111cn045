#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int m1[r][c], m2[r][c], sum[r][c];

    // Input matrices
    for(i=0; i<r; i++)
        for(j=0; j<c; j++) {
            printf("Enter mat1[%d][%d] and mat2[%d][%d]: ", i, j, i, j);
            scanf("%d %d", &m1[i][j], &m2[i][j]);
        }

    // Subtraction and Output
    printf("sub Matrix:\n");
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            sub[i][j] = m1[i][j] - m2[i][j];
            printf("%d\t", sub[i][j]);
        }
        printf("\n");
    }
    return 0;
}