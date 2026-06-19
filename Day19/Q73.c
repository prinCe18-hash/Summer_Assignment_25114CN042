#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
void readMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void addMatrices(int mat1[MAX_ROWS][MAX_COLS] , int mat2[MAX_ROWS][MAX_COLS], int sum[MAX_ROWS][MAX_COLS], int rows , int cols);
int main() {
    int rows, cols;
    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];
    int sumMatrix[MAX_ROWS][MAX_COLS];
    printf("Enter the number of rows and columns (Max %dx%d):" , MAX_ROWS , MAX_COLS);
    if(scanf("%d %d" , &rows , &cols) != 2 || rows<+0 || rows>MAX_COLS || cols<=0 || cols>MAX_COLS) {
        printf("Invalid dimesnsions entered , Existing.\n");
        return 1;
    }
    printf("\n---Matrix 1---\n");
    readMatrix(matrix1 , rows , cols);
    printf("\n---Matrix 2---\n");
    readMatrix(matrix2 , rows , cols);

    addMatrices(matrix1 , matrix2 , sumMatrix , rows , cols);
    printf("\nResultant sum matrix:\n");
    displayMatrix(sumMatrix, rows , cols);
    return 0;
}
void readMatrix(int matrix[MAX_ROWS][MAX_COLS] , int rows, int cols) {
    for(int i=0 ; i<rows ; i++) {
        for( int j=0 ; j<cols ; j++) {
            printf("Enter element [%d][%d]:" , i ,j);
            scanf("%d" , &matrix[i][j]);
        }
    }
}
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS] , int rows , int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void addMatrices(int mat1[MAX_ROWS][MAX_COLS],int mat2[MAX_ROWS][MAX_COLS],int sum[MAX_ROWS][MAX_COLS],int rows , int cols ) {
     for(int i=0 ; i<rows ; i++) {
        for( int j=0 ; j<cols ; j++) {
           sum[i][j] = mat1[i][j] +mat2[i][j];
        }
    }
}
