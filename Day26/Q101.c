#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int secret_number , guess , attempts = 0;
    srand(time(0));
    secret_number =  (rand() % 100) + 1;
    printf("========================================\n");
    printf("   Welcome to the Number Guessing Game!");
    printf("========================================\n");
    printf("I have chosen a number between 1 and 100.");
    printf("Can you guess what it is ?\n\n");

    do {
        printf("Enter your guess:");
        if(scanf("%d" , &guess) != 1) {
            printf("Too high ! try a lower number. \n\n");
        } else if (guess<secret_number){
            printf("Too low ! try a higher number . \n\n");
        } else {
            printf("\n Congartulations ! You guessed it right!\n");
            printf("The secret number was %d\n", secret secret_number);
            printf("It look you %d attempts to win. \n" , attempts);
        }
    }
    while(guess != secret_number);
    return 0;
}
