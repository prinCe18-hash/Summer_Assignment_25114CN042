#include <stdio.h>
void findCommon(int a1[] , int n1 , int a2[] , int n2) {
    printf("Common elements:");
    int matches = 0;
for (int i=0 ; i<n1 ; i++) {
    int dup = 0;
    for (int k=0 ; k<i ; k++) {
        if (a1[i] == a1[k]) {
            dup =1 ;
            break;
        }
    }
    if (dup) continue;
    for (int j=0 ; j<n2 ; j++) {
        if (a1[i] == a2[j]) {
            dup =1;
            break;
        }
    }
}
if (!matches) {
    printf("None") ;
}
printf("\n");
}
int main() {
     int arr1[] = {10,15, 20 , 25 ,30};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {15 , 30 , 45 , 60};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    findCommon( arr1 , size1 , arr2 , size2);
    return 0;
}
