#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("Enter number of elements in the array=");
    scanf("%d",&n);
    if(n<2) {
        printf("Array must have at least two elements .\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d integers :\n" ,n);
    for (int i=0 ; i<n ; i++){
        scanf("%d" ,&arr[i]);
    }
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for (int i=0 ;i<n ;i++) {
        if( arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if ( arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
     if (second_largest == INT_MIN) {
        printf("There is no second largest element (all elements might be equal).\n");
    } else {
        printf("The second largest element is: %d\n", second_largest);
    }

    return 0;
}





   

   
   