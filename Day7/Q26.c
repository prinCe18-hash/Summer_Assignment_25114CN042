#include <stdio.h>
unsigned long long fibonacci(int n);
int main() {
    int terms;
    printf("Enter the position (n) for Fibonacci number: ");
    if (scanf("%d", &terms) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
     if (terms < 0) {
        printf("Position cannot be negative.\n");
    } else {
        printf("Fibonacci number at position %d = %llu\n", terms, fibonacci(terms));
    }
    return 0;
}
unsigned long long fibonacci(int n) {
     if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    } 
    return fibonacci(n - 1) + fibonacci(n - 2);
}
