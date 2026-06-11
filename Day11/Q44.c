#include <stdio.h>
unsigned long long findFactorial(int num);
int main() {
    int n;
    unsigned long long factorial;
    printf("Enter a positive number =");
    scanf("%d", &n);
    if(n<0) {
printf("Error: Factorial of a negative number doesn't exist.\n");
    } else {
        factorial = findFactorial(n);
        printf("Factorial of %d = %llu\n", n, factorial);
    }
    return 0;
}
unsigned long long findFactorial(int num) {
    unsigned long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }

    return fact;
}




