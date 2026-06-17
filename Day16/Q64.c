#include <stdio.h>
#include <stdlib.h>
int compare(const void *a , const void *b) {
    return(*(int*)a - *(int*)b);
}
int removeDuplicates(int arr[], int size) {
    if(size == 0|| size==1) {
        return size;
    }
    qsort(arr , size , sizeof(int), compare);
int unique_idx = 0;
for(int i=0 ; i<size-1 ; i++) {
    if (arr[i] != arr[i+1]) {
        arr[unique_idx++] = arr[i];
    }
}
arr[unique_idx++] = arr[size-1];
}
int main() {
    int arr[] = {4,2,4,1,2,3,1,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:");
    for (int i=0 ; i<size ; i++) printf("%d" , arr[i]);
    printf("\n");
    int new_size = removeDuplicates(arr , size);
    printf("Array after moving duplicates ");
    for (int i=0 ; i<new_size ; i++) printf("%d" , arr[i]);
    printf("/n");
    return 0;
}

