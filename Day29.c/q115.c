#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 100
int string_length(char str[]);
void string_copy(char source[], char destination[]);
void string_concatenate(char str1[], char str2[], char result[]);
void string_reverse(char str[], char result[]);
void clear_buffer();

int main() {
    char str1[STR_SIZE], str2[STR_SIZE], result[STR_SIZE * 2];
    int choice;

    while (1) {
        printf("\n STRING OPERATIONS MENU\n");
        printf("1. Find the Length of a String\n");
        printf("2. Copy a String\n");
        printf("3. Concatenate Two Strings\n");
        printf("4. Reverse a String\n");
        printf("5. Exit\n");
        printf("Enter the choice (1-5): ");
if (scanf("%d", &choice) != 1) {
            printf("Invalid selection! Please enter an integer.\n");
            clear_buffer();
            continue;
        }
        clear_buffer();
         switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, STR_SIZE, stdin);
                for (int i = 0; str1[i] != '\0'; i++) {
                    if (str1[i] == '\n') str1[i] = '\0';
                }
                printf("Length of the string: %d characters\n", string_length(str1));
                break;
  case 2:
                printf("Enter source string to copy: ");
                fgets(str1, STR_SIZE, stdin);
                for (int i = 0; str1[i] != '\0'; i++) {
                    if (str1[i] == '\n') str1[i] = '\0';
                }
                string_copy(str1, result);
                printf("Original String: %s\n", str1);
                printf("Copied String:   %s\n", result);
                break;
 case 3:
                printf("Enter the first string: ");
                fgets(str1, STR_SIZE, stdin);
                for (int i = 0; str1[i] != '\0'; i++) {
                    if (str1[i] == '\n') str1[i] = '\0';
                }

                printf("Enter the second string: ");
                fgets(str2, STR_SIZE, stdin);
                for (int i = 0; str2[i] != '\0'; i++) {
                    if (str2[i] == '\n') str2[i] = '\0';
                }

                string_concatenate(str1, str2, result);
                printf("Combined String: %s\n", result);
                break;
 case 4:
                printf("Enter a string to reverse: ");
                fgets(str1, STR_SIZE, stdin);
                for (int i = 0; str1[i] != '\0'; i++) {
                    if (str1[i] == '\n') str1[i] = '\0';
                }
                string_reverse(str1, result);
                printf("Reversed String: %s\n", result);
                break;

            case 5:
                printf("Exiting String Operations System. Goodbye\n");
                exit(0);

            default:
                printf("Invalid selection. Please pick a choice b/w 1 and 5.\n");
        }
    }
    return 0;
}
int string_length(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
void string_copy(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; 
}
void string_concatenate(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
      while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0'; 
}
void string_reverse(char str[], char result[]) {
    int len = string_length(str);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        result[j] = str[i];
        j++;
    }
    result[j] = '\0'; 
}
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}