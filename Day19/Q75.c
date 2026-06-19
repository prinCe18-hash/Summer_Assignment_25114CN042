#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
void readMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void transposeMatrix(int orignal[MAX_ROWS][MAX_COLS] , int transpose[MAX_ROWS][MAX_COLS],  int rows , int cols);
int main() { 
int rows, cols;
    int matrix[MAX_ROWS][MAX_COLS];
    int transpose[MAX_ROWS][MAX_COLS];
     printf("Enter the number of rows and columns (Max %dx%d):" , MAX_ROWS , MAX_COLS);
    if(scanf("%d %d" , &rows , &cols) != 2 || rows<+0 || rows>MAX_COLS || cols<=0 || cols>MAX_COLS) {
        printf("Invalid dimesnsions entered , Existing.\n");
        return 1;
    }
     printf("\n---Enter Matrix Elements---\n");
    readMatrix(matrix , rows , cols);
    printf("\nOrignal Matrix:\n");
    displayMatrix(matrix , rows , cols);
    transposeMatrix(matrix, transpose , rows , cols);
    printf("\nResultant Difference matrix:\n");
    displayMatrix(transpose, rows , cols);
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

 void transposeMatrix(int orignal[MAX_ROWS][MAX_COLS],int transpose[MAX_ROWS][MAX_COLS], int rows , int cols ) {
     for(int i=0 ; i<rows ; i++) {
        for( int j=0 ; j<cols ; j++) {
          transpose[i][j] = orignal[i][j];
        }
    }
}


