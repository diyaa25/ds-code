#include <stdio.h>

int main()
{
    int matrix[10][10];
    int sparse[100][3];
    int transpose[100][3];

    int rows, cols;
    int i, j, k = 1;
    int nonZero = 0;

    int count[10] = {0};
    int position[10] = {0};

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter elements of the matrix:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];

                nonZero++;
                k++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSparse Matrix :\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= nonZero; i++)
    {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    for (i = 1; i <= nonZero; i++)
    {
        count[sparse[i][1]]++;
    }

    position[0] = 1;

    for (i = 1; i < cols; i++)
    {
        position[i] = position[i - 1] + count[i - 1];
    }

    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = nonZero;

    for (i = 1; i <= nonZero; i++)
    {
        j = sparse[i][1];

        transpose[position[j]][0] = sparse[i][1];
        transpose[position[j]][1] = sparse[i][0];
        transpose[position[j]][2] = sparse[i][2];

        position[j]++;
    }

    printf("\nFast Transpose of Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= nonZero; i++)
    {
        printf("%d\t%d\t%d\n",
               transpose[i][0],
               transpose[i][1],
               transpose[i][2]);
    }

    return 0;
}