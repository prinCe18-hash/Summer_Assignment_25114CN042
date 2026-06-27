#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
struct Marksheet {
    int roll_no;
    char name[50];
    int math;
    int science;
    int english;
    int total;
    float percentage;
    char grade[5];
};
int main() {
    struct Marksheet students[MAX_STUDENTS];
    int count = 0;
    int choice, search_roll, found;

    while (1) {
        printf("\n--- MARKSHEET GENERATION SYSTEM ---\n");
        printf("1. Enter Student Marks\n");
        printf("2. Display All Student Summary\n");
        printf("3. Generate & Print Individual Marksheet\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < MAX_STUDENTS) {
                printf("Enter Roll Number: ");
                scanf("%d", &students[count].roll_no);
                
                printf("Enter Name (single word): ");
                scanf("%s", students[count].name);
                
                printf("Enter Marks for Math (out of 100): ");
                scanf("%d", &students[count].math);
                
                printf("Enter Marks for Science (out of 100): ");
                scanf("%d", &students[count].science);
                
                printf("Enter Marks for English (out of 100): ");
                scanf("%d", &students[count].english);

                students[count].total = students[count].math + students[count].science + students[count].english;
                students[count].percentage = students[count].total / 3.0;

                if (students[count].percentage >= 90) {
                    strcpy(students[count].grade, "A+");
                } else if (students[count].percentage >= 80) {
                    strcpy(students[count].grade, "A");
                } else if (students[count].percentage >= 70) {
                    strcpy(students[count].grade, "B");
                } else if (students[count].percentage >= 60) {
                    strcpy(students[count].grade, "C");
                } else if (students[count].percentage >= 50) {
                    strcpy(students[count].grade, "D");
                } else {
                    strcpy(students[count].grade, "Fail");
                }

                count++;
                printf("Marks recorded and evaluated successfully!\n");
            } else {
                printf("System full!\n");
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("No student data available.\n");
            } else {
                printf("\nRoll No\tName\tTotal\tPercentage\tGrade\n");
                printf("-------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%s\t%d\t%.2f%%\t\t%s\n", 
                           students[i].roll_no, students[i].name, 
                           students[i].total, students[i].percentage, students[i].grade);
                }
            }
        } 
        else if (choice == 3) {
            printf("Enter Roll Number to generate Marksheet: ");
            scanf("%d", &search_roll);
            found = 0;
            for (int i = 0; i < count; i++) {
                if (students[i].roll_no == search_roll) {
                    printf("\n=============================================\n");
                    printf("             OFFICIAL MARKSHEET              \n");
                    printf("=============================================\n");
                    printf(" Roll Number: %-15d Name: %-15s\n", students[i].roll_no, students[i].name);
                    printf("---------------------------------------------\n");
                    printf(" SUBJECT         MAX MARKS      MARKS OBTAINED\n");
                    printf("---------------------------------------------\n");
                    printf(" Math            100            %d\n", students[i].math);
                    printf(" Science         100            %d\n", students[i].science);
                    printf(" English         100            %d\n", students[i].english);
                    printf("---------------------------------------------\n");
                    printf(" TOTAL MARKS:    300            %d\n", students[i].total);
                    printf(" PERCENTAGE:                    %.2f%%\n", students[i].percentage);
                    printf(" FINAL GRADE:                   %s\n", students[i].grade);
                    printf("=============================================\n");
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Student with Roll Number %d not found.\n", search_roll);
            }
        } 
        else if (choice == 4) {
            printf("Exiting program. Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
