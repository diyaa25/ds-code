#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int rowsA, colsA, rowsB, colsB;
    int i, j, k;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < rowsA; i++)
        for(j = 0; j < colsA; j++)
            scanf("%d", &A[i][j]);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < rowsB; i++)
        for(j = 0; j < colsB; j++)
            scanf("%d", &B[i][j]);

    // Addition
    if(rowsA == rowsB && colsA == colsB) {
        printf("\nAddition:\n");
        for(i = 0; i < rowsA; i++) {
            for(j = 0; j < colsA; j++) {
                C[i][j] = A[i][j] + B[i][j];
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nAddition not possible (orders must match).\n");
    }

    // Subtraction
    if(rowsA == rowsB && colsA == colsB) {
        printf("\nSubtraction:\n");
        for(i = 0; i < rowsA; i++) {
            for(j = 0; j < colsA; j++) {
                C[i][j] = A[i][j] - B[i][j];
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nSubtraction not possible (orders must match).\n");
    }

    // Multiplication
    if(colsA == rowsB) {
        printf("\nMultiplication:\n");
        for(i = 0; i < rowsA; i++) {
            for(j = 0; j < colsB; j++) {
                C[i][j] = 0;
                for(k = 0; k < colsA; k++)
                    C[i][j] += A[i][k] * B[k][j];
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nMultiplication not possible (columns of A must equal rows of B).\n");
    }

    // Transpose of A
    printf("\nTranspose of Matrix A:\n");
    for(i = 0; i < colsA; i++) {
        for(j = 0; j < rowsA; j++) {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }

    // Transpose of B
    printf("\nTranspose of Matrix B:\n");
    for(i = 0; i < colsB; i++) {
        for(j = 0; j < rowsB; j++) {
            printf("%d ", B[j][i]);
        }
        printf("\n");
    }

    return 0;
}
