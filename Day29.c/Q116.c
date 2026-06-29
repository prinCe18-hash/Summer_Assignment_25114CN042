#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define STR_SIZE 50
#define LOW_STOCK_THRESHOLD 5
typedef struct {
    int id;
    char name[STR_SIZE];
    int quantity;
    double price;
} Item;
Item inventory[MAX_ITEMS];
int item_count = 0;
void add_item();
void display_inventory();
void update_stock();
void low_stock_alerts();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Product\n");
        printf("2. View Current Inventory\n");
        printf("3. Update Product Stock / Price\n");
        printf("4. Check Low Stock Alerts\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
         if (scanf("%d", &choice) != 1) {
            printf("Invalid selection! Please enter an integer.\n");
            clear_buffer();
            continue;
        }
        clear_buffer(); 

        switch (choice) {
            case 1: add_item(); break;
            case 2: display_inventory(); break;
            case 3: update_stock(); break;
            case 4: low_stock_alerts(); break;
            case 5: 
                printf("Exiting Inventory System. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select b/w 1 and 5.\n");
        }
    }
    return 0;
}
void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory is at maximum capacity. Can't add more products.\n");
        return;
    }

    Item temp;
    printf("Enter Product ID (Integer): ");
    if (scanf("%d", &temp.id) != 1) {
        printf("Invalid ID format. Operation cancelled.\n");
        clear_buffer();
        return;
    }
    clear_buffer();
     for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == temp.id) {
            printf("Error: A product with ID %d already exists.\n", temp.id);
            return;
        }
    }
    printf("Enter Product Name: ");
    fgets(temp.name, STR_SIZE, stdin);
    temp.name[strcspn(temp.name, "\n")] = 0; 

    printf("Enter Initial Quantity: ");
    scanf("%d", &temp.quantity);
    
    printf("Enter Unit Price ($): ");
    scanf("%lf", &temp.price);
    clear_buffer();
inventory[item_count] = temp;
    item_count++;
    printf("Product \"%s\" successfully added into inventory!\n", temp.name);
}
void display_inventory() {
    if (item_count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
double total_value = 0;
    printf("\n%-10s %-25s %-12s %-12s %-15s\n", "ID", "Product Name", "Quantity", "Price", "Total Value");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < item_count; i++) {
        double item_total = inventory[i].quantity * inventory[i].price;
        total_value += item_total;
        
        printf("%-10d %-25s %-12d $%-11.2lf $%-14.2lf\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price,
               item_total);
    }
    printf("----------------------------------------------------------------------------\n");
    printf("Total Warehouse Inventory Value: $%.2lf\n", total_value);
}
void update_stock() {
    if (item_count == 0) {
        printf("Inventory is empty. Nothing to update.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            int update_choice;
            printf("\nUpdating Product: %s\n", inventory[i].name);
            printf("1. Update Quantity Only\n");
            printf("2. Update Price Only\n");
            printf("3. Update Both\n");
            printf("Enter sub-choice (1-3): ");
            scanf("%d", &update_choice);

            if (update_choice == 1 || update_choice == 3) {
                printf("Enter new total quantity: ");
                scanf("%d", &inventory[i].quantity);
            }
            if (update_choice == 2 || update_choice == 3) {
                printf("Enter new unit price ($): ");
                scanf("%lf", &inventory[i].price);
            }
            printf("Product information modified successfully.\n");
            break;
        }
    }
     if (!found) {
        printf("Product ID %d not found.\n", id);
    }
    clear_buffer();
}
void low_stock_alerts() {
    int alert_triggered = 0;
    
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].quantity <= LOW_STOCK_THRESHOLD) {
            if (!alert_triggered) {
                printf("\nLOW STOCK ALERT ITEMS (Threshold: <= %d units) \n", LOW_STOCK_THRESHOLD);
                printf("%-10s %-25s %-12s\n", "ID", "Product Name", "Remaining Stock");
                printf("---------------------------------------------------\n");
            }
            printf("%-10d %-25s %-12d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
            alert_triggered = 1;
        }
         }

    if (!alert_triggered) {
        printf("\n✅ All system stock levels are sufficient. No items running low.\n");
    }
}
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
