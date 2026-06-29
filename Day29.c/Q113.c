#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        printf("\n MENU-DRIVEN CALCULATOR\n");
        printf("1. Add (+)\n");
        printf("2. Subtract (-)\n");
        printf("3. Multiply(*)\n");
        printf("4. Divide (/)\n");
        printf("5. Exit\n");
        printf("Enter your choice among 1 to 5: ");
         if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
         if (choice == 5) {
            printf("Exiting Calculator. Goodbye!\n");
            break;
        }
        if (choice < 1 || choice > 5) {
            printf("Invalid selection! Please choose an option between 1 & 5.\n");
            continue;
        }
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
 case 4:
                if (num2 == 0) {
                    printf("Error : Division by 0 is not allowed!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
        }
    }

    return 0;
}