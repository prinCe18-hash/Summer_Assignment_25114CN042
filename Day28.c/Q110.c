#include <stdio.h>
#include <string.h>
struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};
int main() {
    struct BankAccount account;
    int choice;
    float amount;
    account.accountNumber = 1001;
    strcpy(account.name, "John Doe");
    account.balance = 5000.0; 

    printf("=== Welcome to the Simple Bank System ===\n");
    printf("Account Holder: %s\n", account.name);
    printf("Account Number: %d\n", account.accountNumber);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
              printf("\nYour current balance is: $%.2f\n", account.balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    account.balance += amount;
                    printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, account.balance);
                } else {
                    printf("Invalid amount!\n");
                }
                break;
                  case 3:
                // Withdraw
                printf("\nEnter amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > account.balance) {
                    printf("Insufficient balance! Transaction failed.\n");
                } else if (amount <= 0) {
                    printf("Invalid amount!\n");
                } else {
                    account.balance -= amount;
                    printf("Successfully withdrew $%.2f. New balance: $%.2f\n", amount, account.balance);
                }
                break;

            case 4:
                printf("\nThank you for using our banking system. Goodbye!\n");
                return 0;
                 default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
