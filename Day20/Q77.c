#include <stdio.h>
#define MAX 10 
void readMatrix(int matrix[MAX][MAX], int rows , int cols){
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            printf("Elements [%d][%d]:", i, j);
            scanf("%d" , &matrix[i][j]);
        }
    }
}
void displayMatrix(int matrix[MAX][MAX], int rows , int cols){
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
printf("%d\t" , matrix[i][j]);
        }
        printf("\n");
    }
}
void multiplyMatrices(int first[MAX][MAX],int second[MAX][MAX],int result[MAX][MAX], int r1 , int c1 , int c2){
    for(int i=0 ; i<r1 ; i++){
        for(int j=0 ; j<c2 ; j++){
            result[i][j] = 0;
        }
    }
for(int i=0 ; i<r1 ; i++){
    for(int j=0 ; j<c2 ; j++){
        for (int k=0 ; k<c1 ; k++){
            result[i][j] += first[i][k] * second[k][j];
        }
    }
}
}
int main(){
    int first[MAX][MAX] , second[MAX][MAX] , result[MAX][MAX];
    int r1 , c1 , r2 , c2;
    printf("Enter rows and columns for the first matrix:");
    scanf("%d %d" , &r1 , &c1);
    printf("Enter rows and columns for the second matrix:");
    scanf("%d %d" , &r2 , &c2);

    if(c1 != r2){
        printf("\nError : Multiplication not possible ! Columns of First (%d) must equal rows of second (%d.\n)", c1 , r2);
        return 1;
    }
    printf("\nEnter elements of the first matrix (%dx%d):\n" , r1 , c1);
    readMatrix(first , r1 , c1);
    printf("\nEnter elements of the second matrix (%dx%d):\n" , r2 , c2);
    readMatrix(first , r2 , c2);
    multiplyMatrices(first , second , result , r1 , c1 , c2);
    printf("\nFirst Matrix:\n");
    displayMatrix(first , r1 , c1 );
     printf("\nSecond Matrix:\n");
    displayMatrix(first , r2 , c2 );
     printf("\nResultant Product Matrix:\n");
    displayMatrix(first , r1 , c2 );
    return 0;
}
    
    

