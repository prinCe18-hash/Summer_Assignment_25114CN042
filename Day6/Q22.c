#include <stdio.h>

int main() {
    char binary[33]; 
    int decimal = 0;

    printf("Enter a binary number: ");
    if (scanf("%32s", binary) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; binary[i] != '\0'; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Error: Not a valid binary number.\n");
            return 1;
        }
        decimal = (decimal << 1) + (binary[i] - '0');
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}





