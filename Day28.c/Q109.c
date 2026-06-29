#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define STR_SIZE 50
typedef struct {
    int id;
    char title[STR_SIZE];
    char author[STR_SIZE];
    int is_issued; 
} Book;
Book library[MAX_BOOKS];
int book_count = 0;
void add_book();
void display_books();
void search_book();
void issue_book();
void return_book();
void delete_book();
void clear_input_buffer();
int main() {
    int choice;

    while (1) {
        printf("\n=== LIBRARY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Delete a Book\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: search_book(); break;
            case 4: issue_book(); break;
            case 5: return_book(); break;
            case 6: delete_book(); break;
            case 7: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 7.\n");
        }
    }
    return 0;
}
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Can't add more books.\n");
        return;
    }

    Book b;
    printf("Enter Book ID (Integer): ");
    if (scanf("%d", &b.id) != 1) {
        printf("Invalid ID format. operation cancelled.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == b.id) {
            printf("Error: A book with ID %d already exists.\n", b.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(b.title, STR_SIZE, stdin);
    b.title[strcspn(b.title, "\n")] = 0; 

    printf("Enter Author Name: ");
    fgets(b.author, STR_SIZE, stdin);
    b.author[strcspn(b.author, "\n")] = 0; 

    b.is_issued = 0;
    library[book_count] = b;
    book_count++;
    printf("Book successfully added!\n");
}
void display_books() {
    if (book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\n%-10s %-25s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-25s %-25s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

void search_book() {
    if (book_count == 0) {
        printf("Library is empty.\n");
        return;
    }

    char search_title[STR_SIZE];
    printf("Enter the title to search: ");
    fgets(search_title, STR_SIZE, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) { // Case-insensitive match
            if (!found) {
                printf("\nBook Found:\n");
                printf("%-10s %-25s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
                printf("------------------------------------------------------------------------\n");
            }
            printf("%-10d %-25s %-25s %-15s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
        }
    }
    if (!found) {
        printf("No book found with the title: \"%s\"\n", search_title);
    }
}
void issue_book() {
    int id;
    printf("Enter Book ID to issue: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clear_input_buffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (library[i].is_issued == 1) {
                printf("Sorry , this book is already issued.\n");
            } else {
                library[i].is_issued = 1;
                printf("Book \"%s\" successfully issued.\n", library[i].title);
            }
            return;
        }
    }
    printf("Book ID %d not found.\n", id);
}
void return_book() {
    int id;
    printf("Enter Book ID in order to return: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clear_input_buffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (library[i].is_issued == 0) {
                printf("This book wasn't issued; it is already in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book \"%s\" successfully returned.\n", library[i].title);
            }
            return;
        }
    }
    printf("Book ID %d not found.\n", id);
}

void delete_book() {
    int id, found = 0;
    printf("Enter Book ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clear_input_buffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            found = 1;
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book record deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book ID %d not found.\n", id);
    }
}
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}