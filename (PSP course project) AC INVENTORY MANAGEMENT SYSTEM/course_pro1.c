#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_AC 1000

// Structure for an air conditioner
typedef struct {
    char brand[50];
    char type[50];
    float capacity;
    char energy_rating[10];
    double price;
} AC;

// Function prototypes
void addAC(AC acList[], int *numAC);
void displayAC(AC acList[], int numAC);
void searchAC(AC acList[], int numAC);
void sortAC(AC acList[], int numAC);

// Function to add a new AC to the list
void addAC(AC acList[], int *numAC) {
    if (*numAC == MAX_AC) {
        printf("Error: Maximum number of ACs reached.\n");
        return;
    }

    AC newAC;

    // Get AC details from user
    printf("Enter brand: ");
    scanf("%s", newAC.brand);
    printf("Enter type: ");
    scanf("%s", newAC.type);
    printf("Enter capacity (in tons): ");
    scanf("%f", &newAC.capacity);
    printf("Enter energy rating: ");
    scanf("%s", newAC.energy_rating);
    printf("Enter price: ");
    scanf("%lf", &newAC.price);

    // Add AC to the list
    acList[*numAC] = newAC;
    (*numAC)++;
}

// Function to display all ACs in the list
void displayAC(AC acList[], int numAC) {
    if (numAC == 0) {
        printf("No ACs found.\n");
        return;
    }

    printf("%-20s%-20s%-10s%-15s%-10s\n", "Brand", "Type", "Capacity", "Energy Rating", "Price");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < numAC; i++) {
        printf("%-20s%-20s%-10f%-15s%-10.2f\n", acList[i].brand, acList[i].type, acList[i].capacity, acList[i].energy_rating, acList[i].price);
    }
}
// Function to search the AC list by brand, type, capacity, energy rating, or price
void searchAC(AC acList[], int numAC) {
    if (numAC == 0) {
        printf("No ACs found.\n");
        return;
    }

    int choice;
    char searchString[100];
    int  found = 0;
    // Display search options
    printf("\n\nSearch AC\n");
    printf("------------------------------------\n");
    printf("1. Search by brand\n");
    printf("2. Search by type\n");
    printf("3. Search by capacity\n");
    printf("4. Search by energy rating\n");
    printf("5. Search by price\n");
    printf("------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Search by brand
            printf("\nEnter the brand name to search for: ");
            scanf("%s", searchString);
            for (int i = 0; i < numAC; i++) {
                if (strcmp(acList[i].brand, searchString) == 0) {
                    if (!found) {
                        printf("\nACs matching brand '%s':\n", searchString);
                        printf("%-20s%-20s%-10s%-15s%-10s\n", "Brand", "Type", "Capacity", "Energy Rating", "Price");
                        printf("--------------------------------------------------------\n");
                        found = 1;
                    }
                    printf("%-20s%-20s%-10f%-15s%-10.2f\n", acList[i].brand, acList[i].type, acList[i].capacity, acList[i].energy_rating, acList[i].price);
                }
            }
            break;
        case 2:
            // Search by type
            printf("\nEnter the type to search for: ");
            scanf("%s", searchString);
            for (int i = 0; i < numAC; i++) {
                if (strcmp(acList[i].type, searchString) == 0) {
                    if (!found) {
                        printf("\nACs matching type '%s':\n", searchString);
                        printf("%-20s%-20s%-10s%-15s%-10s\n", "Brand", "Type", "Capacity", "Energy Rating", "Price");
                        printf("--------------------------------------------------------\n");
                        found = 1;
                    }
                    printf("%-20s%-20s%-10f%-15s%-10.2f\n", acList[i].brand, acList[i].type, acList[i].capacity, acList[i].energy_rating, acList[i].price);
                }
            }
            break;
        case 3:
            // Search by capacity
            printf("\nEnter the capacity to search for: ");
            float capacity;
            scanf("%f", &capacity);
            for (int i = 0; i < numAC; i++) {
                if (acList[i].capacity == capacity) {
                    if (!found) {
                        printf("\nACs matching capacity '%f':\n", capacity);
                        printf("%-20s%-20s%-10s%-15s%-10s\n", "Brand", "Type", "Capacity", "Energy Rating", "Price");
                        printf("--------------------------------------------------------\n");
                        found = 1;
                    }
                    printf("%-20s%-20s%-10f%-15s%-10.2f\n", acList[i].brand, acList[i].type, acList[i].capacity, acList[i].energy_rating, acList[i].price);
                    }
            }
            break;
        case 4:
            // Search by energy rating
            printf("\nEnter the energy rating to search for: ");
            scanf("%s", searchString);
            for (int i = 0; i < numAC; i++) {
                if (strcmp(acList[i].energy_rating, searchString) == 0) {
                    if (!found) {
                        printf("\nACs matching energy rating '%s':\n", searchString);
                        printf("%-20s%-20s%-10s%-15s%-10s\n", "Brand", "Type", "Capacity", "Energy Rating", "Price");
                        printf("--------------------------------------------------------\n");
                        found = 1;
                    }
                    printf("%-20s%-20s%-10f%-15s%-10.2f\n", acList[i].brand, acList[i].type, acList[i].capacity, acList[i].energy_rating, acList[i].price);
                }
            }
            break;
        case 5:
            // Search by price
            printf("\nEnter the price to search for: ");
            float price;
            scanf("%f", &price);
            for (int i = 0; i < numAC; i++) {
                if (acList[i].price == price) {
                    if (!found) {
                        printf("\nACs matching price '%.2f':\n", price);
                        printf("%-20s%-20s%-10s%-15s%-10s\n", "Brand", "Type", "Capacity", "Energy Rating", "Price");
                        printf("--------------------------------------------------------\n");
                        found = 1;
                    }
                    printf("%-20s%-20s%-10f%-15s%-10.2f\n", acList[i].brand, acList[i].type, acList[i].capacity, acList[i].energy_rating, acList[i].price);
                }
            }
            break;
        default:
            printf("\nInvalid choice.\n");
            return;
    }

    if (!found) {
        printf("\nNo ACs found matching the search criteria.\n");
    }
}
// Function to sort the AC list by brand, type, capacity, energy rating or price
void sortAC(AC acList[], int numAC) {
    if (numAC == 0) {
        printf("No ACs found.\n");
        return;
    }

    int choice,i,j;
    // Display sort options
    printf("\n\nSort AC\n");
    printf("------------------------------------\n");
    printf("1. Sort by brand\n");
    printf("2. Sort by type\n");
    printf("3. Sort by capacity\n");
    printf("4. Sort by energy rating\n");
    printf("5. Sort by price\n");
    printf("------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    AC temp;
    switch (choice) {
        case 1:
            // Sort by brand
            for (int i = 0; i < numAC - 1; i++) {
                for (int j = 0; j < numAC - i - 1; j++) {
                    if (strcmp(acList[j].brand, acList[j + 1].brand) > 0) {
                        AC temp = acList[j];
                        acList[j] = acList[j + 1];
                        acList[j + 1] = temp;
                    }
                }
            }
            break;
        case 2:
            // Sort by type
            for (int i = 0; i < numAC - 1; i++) {
                for (int j = 0; j < numAC - i - 1; j++) {
                    if (strcmp(acList[j].type, acList[j + 1].type) > 0) {
                        AC temp = acList[j];
                        acList[j] = acList[j + 1];
                        acList[j + 1] = temp;
                    }
                }
            }
            break;
        case 3:
            // Sort by capacity
            for (int i = 0; i < numAC - 1; i++) {
                for (int j = 0; j < numAC - i - 1; j++) {
                    if (acList[j].capacity > acList[j + 1].capacity) {
                        AC temp = acList[j];
                        acList[j] = acList[j + 1];
                        acList[j + 1] = temp;
                    }
                }
            }
            break;
        case 4:
            // Sort by energy rating
            for (int i = 0; i < numAC - 1; i++) {
                for (int j = 0; j < numAC - i - 1; j++) {
                    if (strcmp(acList[j].energy_rating, acList[j + 1].energy_rating) > 0) {
                        AC temp = acList[j];
                        acList[j] = acList[j + 1];
                        acList[j + 1] = temp;
                    }
                }
            }
            break;
        case 5:
            // Sort by price
            for (int i = 0; i < numAC - 1; i++) {
                for (int j = 0; j < numAC - i - 1; j++) {
                    if (acList[j].price > acList[j + 1].price) {
                        AC temp = acList[j];
                        acList[j] = acList[j + 1];
                        acList[j + 1] = temp;
                    }
                }
            }
            break;
        default:
            printf("\nInvalid choice.\n");
            return;
    }

    // Print the sorted AC list
    printf("\nSorted AC List:\n");
    printf("%-20s%-20s%-10s%-15s%-10s\n", "Brand", "Type", "Capacity", "Energy Rating", "Price");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < numAC; i++) {
        printf("%-20s%-20s%-10f%-15s%-10.2f\n", acList[i].brand, acList[i].type, acList[i].capacity, acList[i].energy_rating, acList[i].price);
            }
        }
