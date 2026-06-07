#include <stdio.h>
int reverseNumber(int n, int rev);
int main() {
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int sign = (num < 0) ? -1 : 1;
    int absNum = (num < 0) ? -num : num;
 int result = sign * reverseNumber(absNum, 0);
    printf("Reversed number = %d\n", result);
    return 0;
}
int reverseNumber(int n, int rev) {
    if (n == 0) {
        return rev;
    }
    return reverseNumber(n / 10, rev * 10 + (n % 10));
}
