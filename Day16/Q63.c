#include <stdio.h>
#include <stdlib.h>
int compare(const void *a , const void *b) {
    return(*(int*)a - *(int*)b);
}
int findPair(int arr[] , int size , int target) {
    qsort(arr ,size ,sizeof(int) ,compare);
    int left = 0;
    int right =size-1;
    while(left < right) {
        int current_sum = arr[left] + arr[right];
        if(current_sum == target) {
            printf("Pair found: (%D , %d)\n" , arr[left] , arr[right]);
           return 1;
        }
        else if (current_sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    printf("No pair found with the given sum.\n");
    return 0;
}
int main() {
    int arr[] = {8,7,2,5,3,1};
    int target = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    findPair(arr , size , target);
    return 0;
}

      