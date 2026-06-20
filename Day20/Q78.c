#include <stdio.h>
#define MAX 10
int main(){
    int matrix[MAX][MAX];
    int rows , cols;
    int isSymmetric = 1;
    printf("Enter number of rows and columns :");
    scanf("%d %d", &rows, &cols);
    if(rows != cols) {
        printf("\nThe matrix is not symmetric as its not a square matrix.\n");
        return 0;
    }
    printf("\nEnter elements of the matrix (%dx%d):\n" , rows , cols);
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j< cols ; j++){
            printf("Element [%d][%d]:" , i ,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i=0 ; i<rows ; i++){
        for(int j=i+1 ; j<cols ;j++){
            if(matrix[i][j] != matrix[j][i]){
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric){
            break;
        }
    }
    printf("\nYour Matrix:\n");
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            printf("%d\t" , matrix[i][j]);
        }
        printf("\n");
    }
    if(isSymmetric){
        printf("\nResult: The matrix is symmetric.\n");
    } else {
        printf("\nResult: The matrix is not symmetric.\n");
    }
    return 0;
}
