#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
void display_array(int arr[], int size);
int insert_element(int arr[], int size, int element, int position);
int delete_element(int arr[], int size, int position);
int search_element(int arr[], int size, int element);
void clear_buffer();

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, index;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    size = 3;

    while (1) {
        printf("\n=== ARRAY OPERATIONS MENU ===\n");
        printf("1. Display Array Elements\n");
        printf("2. Insert any Element\n");
        printf("3. Delete any Element\n");
        printf("4. Search for any Element\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
if (scanf("%d", &choice) != 1) {
            printf("Invalid selection! Please enter an integer.\n");
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                display_array(arr, size);
                break;

            case 2:
                printf("Enter integer element to insert: ");
                scanf("%d", &element);
                printf("Enter the target position (1 to %d): ", size + 1);
                scanf("%d", &position);
                
                size = insert_element(arr, size, element, position);
                break;
                 case 3:
                if (size == 0) {
                    printf("Underflow Error: Array is empty! Nothing to delete.\n");
                    break;
                }
                printf("Enter the target position to delete (1 to %d): ", size);
                scanf("%d", &position);
                
                size = delete_element(arr, size, position);
                break;

            case 4:
                printf("Enter integer value to search: ");
                scanf("%d", &element);
                
                index = search_element(arr, size, element);
                if (index != -1) {
                    printf("Element found at Index: %d (Position: %d)\n", index, index + 1);
                } else {
                    printf("Element %d not found inside the array.\n", element);
                }
                break;
                case 5:
                printf("Exiting Array Operations System. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid selection! Please pick a choice between 1 and 5.\n");
        }
    }
    return 0;
    void display_array(int arr[], int size) {
    if (size == 0) {
        printf("Array is currently empty.\n");
        return;
    }
    printf("Current Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n(Total Elements: %d)\n", size);
}
int insert_element(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Overflow Error: Cannot insert element. Array is full.\n");
        return size;
    }
     if (position < 1 || position > size + 1) {
        printf("Error: Invalid position choice!\n");
        return size;
    }
     for (int i = size - 1; i >= position - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = element;
    printf("Successfully inserted %d at position %d.\n", element, position);
    return size + 1;
}
int delete_element(int arr[], int size, int position) {
    if (position < 1 || position > size) {
        printf("Error: Invalid position choice!\n");
        return size;
    }

    int deleted_val = arr[position - 1];
for (int i = position - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Successfully deleted %d from position %d.\n", deleted_val, position);
    return size - 1;
}
int search_element(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; 
        }
    }
    return -1; 
}
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
}