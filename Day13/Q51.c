#include <stdio.h>
int main() {
    int size;
    int sum =0;
    printf("Enter the number of elements=");
    if (scanf("%d",&size) !=1|| size <=0){
        printf("Invalid size entered . Exciting.\n");
        return 1;
}
 int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i=0 ; i<size ; i++){
        printf("Elements %d;" , i+1);
        scanf("%d", &arr[i]);

    }
    int largest = arr[0];
    int smallest = arr[0];
    for( int i=1 ; i<size ; i++) {
        if(arr[i] > largest){
            largest = arr[i];
        }
        if (arr[i]< smallest) {
            smallest = arr[i];
        }
    }
    printf("\n---Results---\n");
    printf("Largest element: %d\n", largest);
     printf("Smallest element: %d\n", smallest);
     return 0;

    }
    