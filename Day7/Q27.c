#include <stdio.h>
int sumOfDigits(int n);
int main() {
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
     int temp = (num < 0) ? -num : num;
    printf("Sum of digits of %d = %d\n", num, sumOfDigits(temp));
    return 0;
}
int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}



    
