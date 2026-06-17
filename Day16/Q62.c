#include <stdio.h>
#include <stdlib.h>
int compare(const void *a , const void *b) {
    return (*(int*)a -*(int*)b);
}
int findMaxFrequencyElement(int arr[], int size) {
    if(size==0) return -1;
    qsort(arr , size , sizeof(int), compare);
    int maxElement = arr[0];
    int maxCount =1 ;
    int currentElement = arr[0];
    int currentCount=1;
for (int i=1 ; i<size; i++) {
    if(arr[i] == currentElement) {
        currentCount++;
    } else {
        if(currentCount > maxCount) {
            maxCount = currentCount;
            maxElement= currentElement;
        }
        currentElement = arr[i];
        currentCount = 1;
    }
}
if (currentCount > maxCount) {
    maxCount = currentCount;
    maxElement = currentElement;
}
printf("Maximum frequency is : %d\n" ,maxCount);
return maxElement;
}
int main() {
    int arr[] = {1,3,2,1,4,1,3,2,2,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findMaxFrequencyElement(arr , size);
    printf("The element with max frequescy is :%d\n" , result);
    return 0;
}


 