#include <stdio.h>
int main() {
    int size;
    int even_count = 0;
    int odd_count = 0;
    printf("Enter the number of elements:");
    if(scanf("%d", &size) !=1 || size <= 0){
        printf("Invalid size entered . Existing.\n");
        return 1;
    }
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(int i=0 ; i<size ; i++){
        printf("Element %d:", i+1);
        scanf("%d",&arr[i]);
    }
    for ( int i=0 ; i<size ; i++){
        if (arr[i] %2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
     printf("\n--- Results ---\n");
    printf("Total Even elements: %d\n", even_count);
    printf("Total Odd elements: %d\n", odd_count);

    return 0;
}


    
    