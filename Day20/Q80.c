#include <stdio.h>
#define MAX 10 
int main() {
    int matrix[MAX][MAX];
    int rows, cols;
     printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
     printf("\nEnter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
     printf("\nYour Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
     for (int j = 0; j < cols; j++) {
        printf("-------\t");
    }
    printf("\n");
     for (int j = 0; j < cols; j++) {
        int colSum = 0; 
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
             }
        printf("%d\t", colSum);
    }
    printf("<- Column-wise Sum\n");

    return 0;
}