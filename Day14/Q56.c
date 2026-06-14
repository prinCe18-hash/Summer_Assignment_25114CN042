#include <stdio.h>
int main() {
    int n , duplicate_found =0;
    printf("Enter number of elements in the array:");
    scanf("%d" , &n);
     
    int arr[n];
    int visited[n];
    printf("Enter %d integers:\n", n);
    for (int i=0 ; i<n ; i++) {
        scanf("%d" , &arr[i]);
        visited[i] = 0;
    }
    printf("Duplicate elements in the array are:");
    for (int i=0 ; i<n ; i++) {
if (visited[i] == 1) {
    continue;
}
int count = 1 ;
for( int j=i+1 ; j<n ; j++) {
    if (arr[i] == arr[j]) {
        count++;
        visited[j] = 1;
    }
}
if (count > 1) {
    printf("%d" , arr[i]);
    duplicate_found = 1;
}
    }
    if (!duplicate_found) {
        printf("None");
    }
    printf("\n");
    return 0;
}


   