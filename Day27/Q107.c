#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 100
struct SalaryRecord {
    int emp_id;
    char name;
    float basic_salary;
    float hra;        
    float da;         
    float pf;         
    float net_salary; 
};

int main() {
    struct SalaryRecord staff[MAX_EMPLOYEES];
    int count = 0;
    int choice, search_id, found;

    while (1) {
        printf("\n--- SALARY MANAGEMENT SYSTEM ---\n");
        printf("1. Calculate & Add Salary Slip\n");
        printf("2. Display All Salary Records\n");
        printf("3. Search Employee Pay Slip\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (count < MAX_EMPLOYEES) {
                printf("Enter Employee ID: ");
                scanf("%d", &staff[count].emp_id);
                
                printf("Enter Name (single word): ");
                scanf("%s", staff[count].name);
                
                printf("Enter Basic Salary: ");
                scanf("%f", &staff[count].basic_salary);
                staff[count].hra = staff[count].basic_salary * 0.20;
                staff[count].da = staff[count].basic_salary * 0.10;
                staff[count].pf = staff[count].basic_salary * 0.12;
                staff[count].net_salary = (staff[count].basic_salary + staff[count].hra + staff[count].da) - staff[count].pf;

                count++;
                printf("Salary calculated and record saved successfully!\n");
            } else {
                printf("System full!\n");
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("No salary records found.\n");
            } else {
                printf("\nID\tName\tBasic\tHRA\tDA\tPF\tNet Salary\n");
                printf("------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", 
                           staff[i].emp_id, staff[i].name, staff[i].basic_salary, 
                           staff[i].hra, staff[i].da, staff[i].pf, staff[i].net_salary);
                }
            }
        } 
        else if (choice == 3) {
            printf("Enter Employee ID to fetch Pay Slip: ");
            scanf("%d", &search_id);
            found = 0;
            for (int i = 0; i < count; i++) {
                if (staff[i].emp_id == search_id) {
                    printf("\n===================================\n");
                    printf("          SALARY PAY SLIP          \n");
                    printf("===================================\n");
                    printf("Employee ID   : %d\n", staff[i].emp_id);
                    printf("Employee Name : %s\n", staff[i].name);
                    printf("-----------------------------------\n");
                    printf("Basic Salary  : + Rs. %.2f\n", staff[i].basic_salary);
                    printf("HRA (20%%)     : + Rs. %.2f\n", staff[i].hra);
                    printf("DA (10%%)      : + Rs. %.2f\n", staff[i].da);
                    printf("PF Deduct(12%%): - Rs. %.2f\n", staff[i].pf);
                    printf("-----------------------------------\n");
                    printf("NET TAKE-HOME :   Rs. %.2f\n", staff[i].net_salary);
                    printf("===================================\n");
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Salary record for ID %d not found.\n", search_id);
            }
        } 
        else if (choice == 4) {
            printf("Exiting system. Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
