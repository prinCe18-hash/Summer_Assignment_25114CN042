#include <stdio.h>
void moveZeroesTOEnd(int arr[] ,int size) {
    int nonZeroPos = 0;
    for(int i=0 ;i<size ;i++) {
        if(arr[i] !=0) {
            int temp = arr[i];
            arr[i] = arr[nonZeroPos];
            arr[arr[i]==0 ? i : nonZeroPos] = temp;
            temp = arr[i];
            arr[i] = arr[nonZeroPos];
            arr[nonZeroPos] = temp;
            nonZeroPos++;
        }
    }
}
void printArray(int arr[] , int size) {
    for(int i=0 ; i<size ; i++) {
        printf("%d" , arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {1,0,2,3,0,4,0,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:");
    printArray(arr ,size);
    moveZeroesTOEnd(arr ,size);
    printf("Array after moving zeroes:");
    printArray(arr,size);
    return 0;
}






