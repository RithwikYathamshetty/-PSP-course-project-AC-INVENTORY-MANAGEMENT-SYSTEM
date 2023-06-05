#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"course_pro1.c"
#define MAX_AC 1000

int main() {
	/*int MAX_AC;
	printf("\n Enter Maximum no. of AC's:");
	scanf("%d",&MAX_AC);*/
    AC acList[MAX_AC];
    int numAC = 0;
    int choice;

    while (1) {
        // Display menu
        
        printf("\n\nAC Inventory Management System\n");
        printf("------------------------------------\n");
        printf("1. Add AC\n");
        printf("2. Display ACs\n");
        printf("3. Search AC\n");
        printf("4. Sort AC\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAC(acList, &numAC);
                break;
            case 2:
                displayAC(acList, numAC);    
                break;
            case 3:
                searchAC(acList, numAC);
                break;
            case 4:
                sortAC(acList, numAC);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}


