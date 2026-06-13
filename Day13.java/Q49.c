#include <stdio.h>
int main() {
    int size;
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
    printf("\n");
    return 0;
}



