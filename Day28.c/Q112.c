#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define STR_SIZE 50
typedef struct {
    char name[STR_SIZE];
    char phone[STR_SIZE];
    char email[STR_SIZE];
} Contact;
Contact phonebook[MAX_CONTACTS];
int contact_count = 0;
void add_contact();
void display_contacts();
void search_contact();
void delete_contact();
void clear_buffer();

int main() {
    int choice;
     while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add a New Contact\n");
        printf("2. Display all the Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete any Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_buffer();
            continue;
        }
        clear_buffer();
         switch (choice) {
            case 1: add_contact(); break;
            case 2: display_contacts(); break;
            case 3: search_contact(); break;
            case 4: delete_contact(); break;
            case 5: 
                printf("Exiting System. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Select between 1 and 5.\n");
        }
    }
    return 0;
}
void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Phonebook is full! Can't add more contacts.\n");
        return;
    }

    Contact c;

    printf("Enter the Name: ");
    fgets(c.name, STR_SIZE, stdin);
    c.name[strcspn(c.name, "\n")] = 0;
    printf("Enter the Phone Number: ");
    fgets(c.phone, STR_SIZE, stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter the Email Address: ");
    fgets(c.email, STR_SIZE, stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    phonebook[contact_count] = c;
    contact_count++;
    printf("Contact is saved successfully!\n");
}
void display_contacts() {
    if (contact_count == 0) {
        printf("No contacts saved in your phonebook.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-25s\n", "No.", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%-5d %-20s %-15s %-25s\n", 
               i + 1, phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }
}
void search_contact() {
    if (contact_count == 0) {
        printf("Phonebook empty.\n");
        return;
    }
    char search_name[STR_SIZE];
    printf("Enter the name to search: ");
    fgets(search_name, STR_SIZE, stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(phonebook[i].name, search_name) == 0) {
            if (!found) {
                printf("\nContact Found:\n");
                printf("%-20s %-15s %-25s\n", "Name", "Phone", "Email");
                printf("---------------------------------------------------\n");
            }
            printf("%-20s %-15s %-25s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found with such name: \"%s\"\n", search_name);
    }
}
void delete_contact() {
    if (contact_count == 0) {
        printf("Phonebook empty. Nothing to delete.\n");
        return;
    }

    char delete_name[STR_SIZE];
    printf("Please enter exact contact name to delete: ");
    fgets(delete_name, STR_SIZE, stdin);
    delete_name[strcspn(delete_name, "\n")] = 0;
 int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(phonebook[i].name, delete_name) == 0) {
            found = 1;
            for (int j = i; j < contact_count - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            contact_count--;
            printf("Contact \"%s\" deleted successfully.\n", delete_name);
            break; 
        }
    }
    if (!found) {
        printf("Contact matching \"%s\" not found.\n", delete_name);
    }
}
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}