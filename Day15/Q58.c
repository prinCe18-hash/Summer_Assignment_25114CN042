#include <stdio.h>
void reverse(int arr[], int start , int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
}
void rotateLeft(int arr[], int size , int k) {
    k = k%size;
    if (k == 0) return;
    reverse(arr, 0, k-1);
     reverse(arr, k, size -1);
      reverse(arr, k, size -1);
}
void printArray(int arr[] , int size) {
    for(int i=0 ;i<size ;i++) {
        printf("%d" , arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k=3;
    printf("Original array:");
    printArray(arr ,size);
    rotateLeft(arr , size , k);
    printf("Left rotated by %d positions" , k);
    printArray(arr , size);
    return 0;
}




