#include <stdio.h>
void printtFibonacci(int n) {
    long long t1 =0 , t2=1 , nextTerm;
    if(n<=0) {
        printf("Please enetr a positive number greater than 0.\n");
        return;
    }
    printf("Fibonacci Sequence:");
    for(int i =1; i<=n; i++) {
        printf("%lld",t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}
int main() {
    int terms;
    printf("Enter the number of terms :");
    scanf("%d", &terms);
    printtFibonacci(terms);
    return 0;
}



    
       