#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 100
struct Employee {
    int id;
    char name;
    float salary;
};
int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice, search_id, found;
    while (1) {
        printf("\n--- EMPLOYEE MANAGEMENT SYSTEM ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (count < MAX_EMPLOYEES) {
                printf("Enter Employee ID: ");
                scanf("%d", &employees[count].id);
                
                printf("Enter Name (single word): ");
                scanf("%s", employees[count].name);
                
                printf("Enter Salary: ");
                scanf("%f", &employees[count].salary);
                
                count++;
                printf("Employee record added successfully!\n");
            } else {
                printf("System is full! Cannot add more employees.\n");
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("No employee records found.\n");
            } else {
                printf("\nID\tName\tSalary\n");
                printf("-------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
                }
            }
        } 
        else if (choice == 3) {
            printf("Enter Employee ID to search: ");
            scanf("%d", &search_id);
            found = 0;
            for (int i = 0; i < count; i++) {
                if (employees[i].id == search_id) {
                    printf("\nEmployee Found!\n");
                    printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Employee with ID %d not found.\n", search_id);
            }
        } 
        else if (choice == 4) {
            printf("Exiting program. Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
