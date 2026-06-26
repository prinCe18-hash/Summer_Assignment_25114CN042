#include <stdio.h>
#include<stdbool.h>
const int CORRECT_PIN = 1234;
double balance = 5000.00;
int entered_pin;
int choice;
double amount;
bool is_authenticated = false;
printf("Welcome to the Apex Bank ATM \n");
printf("Please enter your 4-digit PIN: ");
    if (scanf("%d", &entered_pin) != 1) {
        printf("\n Error: Invalid input system. Transaction aborted.\n");
        return 1;
    }

    if (entered_pin == CORRECT_PIN) {
        is_authenticated = true;
        printf("\n PIN Verified Successfully!\n");
    } else {
        printf("\nIncorrect PIN. Access Denied.\n");
        return 0;
    }
    while (is_authenticated) {
        printf("\n-----------------------------------------\n");
        printf("                MAIN MENU                \n");
        printf("-----------------------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Cash\n");
        printf("3. Withdraw Cash\n");
        printf("4. Exit / Return Card\n");
        printf("Choose an option (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n Invalid option. System resetting...\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
            printf("\n Current Available Balance: ₹%.2f\n", balance);
                break;
                case 2:
                printf("\nEnter deposit amount: ₹");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf(" Invalid deposit amount.\n");
                    while (getchar() != '\n');
                } else {
                    balance += amount;
                    printf("₹%.2f successfully deposited.\n", amount);
                    printf(" New Balance: ₹%.2f\n", balance);
                }
                break;
                case 3:
               printf("\nEnter withdrawal amount: ₹");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf(" Invalid withdrawal amount.\n");
                    while (getchar() != '\n');
                } else if (amount > balance) {
                    printf(" Transaction Failed: Insufficient balance!\n");
                    printf(" Your current balance is ₹%.2f\n", balance);
                } else {
                    balance -= amount;
                    printf(" Please collect your cash: ₹%.2f\n", amount);
                    printf(" Remaining Balance: ₹%.2f\n", balance);
                }
                break;
                case 4:
                printf("\nThank you for using Apex Bank ATM. Have a great day!\n");
                is_authenticated = false; 
                break;

            default:
                printf("\n Invalid choice! Please select a valid option from the menu.\n");
        }
    

    return 0;
}






    