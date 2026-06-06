#include <stdio.h>
int main() {
    double base, result = 1.0;
    long long exp;

    printf("Enter base (x): ");
    if (scanf("%lf", &base) != 1) {
        printf("Invalid base input.\n");
        return 1;
    }
     printf("Enter exponent (n): ");
    if (scanf("%lld", &exp) != 1) {
        printf("Invalid exponent input.\n");
        return 1;
    }

    long long abs_exp = exp < 0 ? -exp : exp;
    double current_product = base;

     while (abs_exp > 0) {
        if (abs_exp % 2 == 1) {
            result *= current_product;
        }
        current_product *= current_product;
        abs_exp /= 2;
    }
    if (exp < 0) {
        result = 1.0 / result;
    }

    printf("%.2f^%lld = %f\n", base, exp, result);

    return 0;


}





