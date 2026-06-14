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
    printf("Enter the value to search for :");
    scanf("%d", &target);
for (int i =0; i<n ; i++) {
    if (arr[i] == target) {
        printf("Element found at index %d (Position %d).\n", i , i+1);
        found =1;
        break;
    }
}
if (!found) {
    printf("Enter %d is not present in the array.\n", target);
}
return 0;
}




    