#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to hold student data
struct Student {
    int roll_no;
    char name[50];
    float gpa;
};
int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0; 
    int choice, search_roll, found;

    while (1) {
        printf("\n--- STUDENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < MAX_STUDENTS) {
                printf("Enter Roll Number: ");
                scanf("%d", &students[count].roll_no);
                
                printf("Enter Name: ");
                scanf("%s", students[count].name);
                
                printf("Enter GPA: ");
                scanf("%f", &students[count].gpa);
                
                count++;
                printf("Student added successfully!\n");
            } else {
                printf("System full!\n");
            }
        } 
        else if (choice == 2) {
            // Display All
            if (count == 0) {
                printf("No records found.\n");
            } else {
                printf("\nRoll No\tName\tGPA\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%s\t%.2f\n", students[i].roll_no, students[i].name, students[i].gpa);
                }
            }
        } 
        else if (choice == 3) {
            printf("Enter Roll Number to search: ");
            scanf("%d", &search_roll);
            found = 0;
            for (int i = 0; i < count; i++) {
                if (students[i].roll_no == search_roll) {
                    printf("\nFound! Name: %s, GPA: %.2f\n", students[i].name, students[i].gpa);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Student not found.\n");
            }
        } 
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
