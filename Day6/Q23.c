#include <stdio.h>
int main() {
     int num, count = 0;
printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int original_num = num;

    while (num > 0) {
        num = num & (num - 1); // Clears the lowest set bit
        count++;
    }
     printf("Number of set bits in %d is: %d\n", original_num, count);

    return 0;

}




