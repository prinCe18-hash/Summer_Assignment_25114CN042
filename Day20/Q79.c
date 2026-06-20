#include <stdio.h>
#define MAX 10
int main(){
    int matrix[MAX][MAX];
    int rows , cols;
    printf("Enter number of rows and columns :");
    scanf("%d %d", &rows, &cols);
    printf("\nEnter elements of the matrix (%dx%d):\n" , rows , cols);
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j< cols ; j++){
            printf("Element [%d][%d]:" , i ,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nMatrix and row wise sum:\n");
    for(int i=0 ; i<rows ; i++){
        int rowSum = 0;
        for(int j=0 ; j<cols ; j++){
            printf("%d\t", matrix[i][j]);
            rowSum += matrix[i][j];
        }
        printf("| Sum = %d\n" , rowSum);

    }
    return 0;
}

