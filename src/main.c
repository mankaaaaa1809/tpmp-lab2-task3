#include "../include/abonent.h"

/*a client using abonent.c server and abonent.h interface*/

int main() {
	struct ABON1 abonents[MAX_ABONENTS];
	int count = 0;
	int choice;
	
	printf("Subscriber database program\n");
	
	do {
		printf("\nMenu:\n");
		printf("1. Enter subscriber data\n");
		printf("2. Sort alphabetically\n");
		printf("3. Add 10 rub. bonus (connection > 10 years ago)\n");
		printf("4. Show subscribers with negative balance after deduction\n");
		printf("5. Show tariff statistics\n");
		printf("6. Show all subscribers\n");
		printf("0. Exit\n");
		printf("Select action: ");
		scanf("%d", &choice);
		
		switch(choice) {
		case 1:
			count = input_abonents(abonents, MAX_ABONENTS);
			printf("Entered %d subscribers\n", count);
			break;
			
		case 2:
			if (count > 0) {
				sort_abonents(abonents, count);
				printf("Subscribers sorted alphabetically\n");
				print_all_abonents(abonents, count);
			} else {
				printf("First enter subscriber data!\n");
			}
			break;
			
		case 3:
			if (count > 0) {
				add_bonus(abonents, count);
				printf("After adding bonus:\n");
				print_all_abonents(abonents, count);
			} else {
				printf("First enter subscriber data!\n");
			}
			break;
			
		case 4:
			if (count > 0) {
				print_negative_balance(abonents, count);
			} else {
				printf("First enter subscriber data!\n");
			}
			break;
			
		case 5:
			if (count > 0) {
				print_tariff_stats(abonents, count);
			} else {
				printf("First enter subscriber data!\n");
			}
			break;
			
		case 6:
			if (count > 0) {
				print_all_abonents(abonents, count);
			} else {
				printf("Subscriber list is empty!\n");
			}
			break;
			
		case 0:
			printf("Exiting program\n");
			break;
			
		default:
			printf("Invalid choice! Try again.\n");
		}
	} while(choice != 0);
	
	return 0;
}
