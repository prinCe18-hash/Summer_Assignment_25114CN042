#include <stdio.h>
int main(){
    int size;
    int sum = 0;
    float average;
    printf("Enter the number of elements=");
    if (scanf("%d",&size) !=1 || size<=0){
        printf("Invalid size entered . existing.\n");
        return 1;
    }
    int arr[size];
    printf("Enter %d elements:\n",size);
    for (int i=0 ;i<size ; i++) {
        printf("Elements %d:", i+1);
        scanf("%d" , &arr[i]);
        sum += arr[i];
    }
    average = (float)sum / size;
    printf("\n---Results ---\n");
    printf("Sum: %d\n" ,sum);
    printf("Average: %.2f/n" , average);
    return 0;
}



