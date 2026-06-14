#include <stdio.h>
int main() {
    int n , target , found = 0;
    printf("Enter the number of elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers :\n", n);
    for (int i = 0; i<n ;i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the elements to find its frequency:");
     scanf("%d", &target);
     for (int i=0 ; i<n ;i++)
     if (arr[i] == target) {
found++;
     }
     printf("The element %d occurs %d time(s) in the array.\n", target, found);

    return 0;
}




