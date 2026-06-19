#include <stdio.h>
#include <stdlib.h>


int R1 = 2; // number of rows in Matrix-1
int C1 = 2; // number of columns in Matrix-1
int R2 = 2; // number of rows in Matrix-2
int C2 = 3; 

void multiplyMatrix(int m1[][C1], int m2[][C2])
{
    int result[R1][C2];

    printf("Resultant Matrix is:\n");

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }

            printf("%d\t", result[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    
    int m1[R1][C1] = { { 1, 1 }, { 2, 2 } };

    int m2[R2][C2] = { { 1, 1, 1 }, { 2, 2, 2 } };

    
    if (C1 != R2) {
        printf("Wrong");
    }

    
    multiplyMatrix(m1, m2);

    return 0;
}