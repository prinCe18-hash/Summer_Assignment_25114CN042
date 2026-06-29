#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLS 6
#define TICKET_PRICE 15.00
int seats[ROWS][COLS] = {0}; 
void display_seating();
void book_ticket();
void cancel_ticket();

int main() {
    int choice;
        while (1) {
        printf("\n=== MOVIE TICKET BOOKING SYSTEM ===\n");
        printf("1. View Seating Chart\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
 switch (choice) {
            case 1: 
                display_seating(); 
                break;
            case 2: 
                book_ticket(); 
                break;
            case 3: 
                cancel_ticket(); 
                break;
            case 4: 
                printf("Thank you for using our booking system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}
void display_seating() {
    printf("\n\t  === SCREEN THIS WAY ===\n\n");
    printf("       ");
    for (int j = 0; j < COLS; j++) {
        printf("Col %d ", j + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d:  ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                printf("[ O ] ");
            } else {
                printf("[ X ] "); 
            }
        }
        printf("\n");
    }
    printf("\nLegend: [ O ] = Available ($%.2f)   [ X ] = Booked\n", TICKET_PRICE);
}
void book_ticket() {
    int r, c;
    
    printf("\nEnter Row number (1-%d): ", ROWS);
    scanf("%d", &r);
    printf("Enter Column number (1-%d): ", COLS);
    scanf("%d", &c);
 int row_idx = r - 1;
    int col_idx = c - 1;
 if (row_idx < 0 || row_idx >= ROWS || col_idx < 0 || col_idx >= COLS) {
        printf("Error: Invalid seat selection. Row or Column out of range.\n");
        return;
    }
    if (seats[row_idx][col_idx] == 1) {
        printf("Sorry, Row %d Column %d is already booked!\n", r, c);
    } else {
        seats[row_idx][col_idx] = 1;
        printf("Success! Seat Row %d Column %d is now reserved.\n", r, c);
        printf("Please pay: $%.2f at the counter.\n", TICKET_PRICE);
    }
}
void cancel_ticket() {
    int r, c;
    
    printf("\nEnter Row number (1-%d) to cancel: ", ROWS);
    scanf("%d", &r);
    printf("Enter Column number (1-%d) to cancel: ", COLS);
    scanf("%d", &c);

    int row_idx = r - 1;
    int col_idx = c - 1;

    if (row_idx < 0 || row_idx >= ROWS || col_idx < 0 || col_idx >= COLS) {
        printf("Error: Invalid seat selection.\n");
        return;
    }
     if (seats[row_idx][col_idx] == 0) {
        printf("This seat is already empty/not booked.\n");
    } else {
        seats[row_idx][col_idx] = 0;
        printf("Success! Booking for Row %d Column %d has been cancelled.\n", r, c);
    }
}