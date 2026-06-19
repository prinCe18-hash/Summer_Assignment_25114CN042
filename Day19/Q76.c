#include <stdio.h>
#define MAX_SIZE 10
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void calculateDiagonalSums(int matrix[MAX_SIZE][MAX_SIZE] , int size , int *secondarySum ,  int *primarySum);
int main() { 
int size;
    int matrix[MAX_SIZE][MAX_SIZE];
      int primarySum=0 ; int secondarySum = 0;
     printf("Enter the size of square matrix (Max %d):" , MAX_SIZE);
    if(scanf("%d" , &size) != 2 || size<=0  || size>MAX_SIZE) {
        printf("Invalid matrix size entered , Existing.\n");
        return 1;
    }
    printf("\n---Enter Matrix Elements---\n");
    readMatrix(matrix , size);
    printf("\nMatrix:\n");
    displayMatrix(matrix ,size);
    calculateDiagonalSums(matrix, size , &primarySum , &secondarySum);
    printf("\nSum of Principal(Primary) Diagonal:%d\n" , primarySum);
    printf("Sum of secondary diagonal:%d\n" , secondarySum);
    return 0;
}
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE] , int size) {
    for(int i=0 ; i<size ; i++) {
        for( int j=0 ; j<size ; j++) {
            printf("Enter element [%d][%d]:" , i ,j);
            scanf("%d" , &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE] , int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void calculateDiagonalSums(int matrix[MAX_SIZE][MAX_SIZE],int size , int *primarySum , int *secondarySum ) {
    *primarySum = 0;
    *secondarySum = 0;
     for(int i=0 ; i<size ; i++) {
        *primarySum += matrix[i][i];
        *secondarySum += matrix[i][size -1 -i];
    }
}

