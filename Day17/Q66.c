#include <stdio.h>
#include <stdlib.h>
int compare( const void *a, const void *b) {
   return (*(int*)a -*(int*)b);
}
void printUnion(int arr1[] , int size1 , int arr2[] , int size2) {
    qsort(arr1 , size1 , sizeof(int) , compare);
     qsort(arr2 , size2 , sizeof(int) , compare);
     int i=0 ; int j=0;
     printf("Union of arrays:");
     while(i<size1 && j < size2) {
        while(i > 0 && i< size1 && arr1[i] == arr1[i-1]) {
i++;
        }
         while(j > 0 && j< size2 && arr2[j] == arr2[j-1]) {
j++;
        }
        if (i >= size1 || j>= size2) break;
        if (arr1[i] < arr2[j]) {
            printf("%d" , arr1[i++]);
        } else if (arr2[j] < arr1[i]) {
            printf("%d" , arr2[j++]);
        } else {
            printf("%d" , arr1[i++]);
            j++;
        }
     }
while (i < size1) {
    if(i==0 || arr1[i] != arr1[i-1]) {
        printf("%d" , arr1[i]);
    }
    i++;
}
while (j < size2) {
    if(j==0 || arr2[j] != arr2[j-1]) {
        printf("%d" , arr2[j]);
    }
    j++;
}
printf("\n");
}
int main() {
    int arr1[] = {4,2,4,1,6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2,3,5,6,2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printUnion( arr1 , size1 , arr2 , size2);
    return 0;

}




