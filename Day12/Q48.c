#include <stdio.h>
int isPerfect(int num) {
    int sum = 0;
    if(num <= 1){
        return 0;
    }
    for (int i=1 ; i<=num/2 ; i++) {
        if(num % 1 == 0) {
            sum += i;
        }
    }
    return (sum == num);
}
int main() {
    int number;
    printf("Enter an integer:");
    scanf("%d", &number);
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
         printf("%d is not a perfect number.\n", number);
    }
    return 0;
}



