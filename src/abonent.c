#include "abonent.h"

/*implementation of functions and structures from abonent.h, usage: main.c client*/

//function for inputting abonents data through console
int input_abonents(struct ABON1 abonents[], int max_size) {
	int count;
	printf("enter the number of abonents (max: %d): ", max_size);
	scanf("%d", &count);
    
	if (count > max_size) {
		printf("Maximum size exceeded! Using %d\n", max_size);
		count = max_size;
	}

	for (int i = 0; i < count; i++) {
		printf("Full name and initials: ");
		scanf(" %[^\n]", abonents[i].fio);
		
		printf("Phone number: ");
		scanf("%s", abonents[i].phone);
		
		printf("Connection date (year month day): ");
		scanf("%d %d %d", 
			  &abonents[i].connect_date.year,
			  &abonents[i].connect_date.month,
			  &abonents[i].connect_date.day);
		
		printf("Tariff plan: ");
		scanf("%s", abonents[i].tariff);
		
		printf("Accrued amount: ");
		scanf("%f", &abonents[i].accrued);
		
		printf("Account balance: ");
		scanf("%f", &abonents[i].balance);
	}
	
	return count;
}

//function for comparing abonents by first letters
int compare_abonents(const void *a, const void *b) {
	struct ABON1 *abon1 = (struct ABON1 *)a;
	struct ABON1 *abon2 = (struct ABON1 *)b;
	
	int result = strcmp(abon1->fio, abon2->fio);
	return result;
}

//function for sorting abonents in alphabet order
void sort_abonents(struct ABON1 abonents[], int count) {
	qsort(abonents, count, sizeof(struct ABON1), compare_abonents);
}

//function for determining whether 10 years passed
int is_more_than_10_years(struct Date connect_date) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	int current_year = tm.tm_year + 1900;
	int current_month = tm.tm_mon + 1;
	int current_day = tm.tm_mday;
	
	// Simple check: if year difference > 10
	if (current_year - connect_date.year > 10) {
		return 1;
	}
	// If difference is exactly 10 years, check months and days
	else if (current_year - connect_date.year == 10) {
		if (current_month > connect_date.month) {
			return 1;
		}
		else if (current_month == connect_date.month && current_day >= connect_date.day) {
			return 1;
		}
	}
	
	return 0;
}

//function for adding 10 rub on abonent’s account
void add_bonus(struct ABON1 abonents[], int count) {
	int added_count = 0;
	
	for (int i = 0; i < count; i++) {
		if (is_more_than_10_years(abonents[i].connect_date)) {
			abonents[i].balance += 10.0;
			added_count++;
		}
	}
	
	printf("Bonus added to %d subscribers\n", added_count);
}

//function for outputting abonents with negative balance
void print_negative_balance(struct ABON1 abonents[], int count) {
	printf("\nSubscribers with negative balance after deduction\n");
	int found = 0;
	
	for (int i = 0; i < count; i++) {
		float after_deduction = abonents[i].balance - abonents[i].accrued;
		if (after_deduction < 0) {
			printf("Subscriber: %s\n", abonents[i].fio);
			printf("Phone: %s\n", abonents[i].phone);
			printf("Tariff: %s\n", abonents[i].tariff);
			printf("Accrued: %.2f, Balance: %.2f, After deduction: %.2f\n", 
				   abonents[i].accrued, abonents[i].balance, after_deduction);
			found = 1;
		}
	}
	
	if (!found) {
		printf("No subscribers with negative balance after deduction\n");
	}
}

//function for outputting number of abonents for each tariff
void print_tariff_stats(struct ABON1 abonents[], int count) {
	printf("\nTariff plan statistics\n");
	
	// Array to store unique tariffs and counters
	char unique_tariffs[MAX_ABONENTS][MAX_TARIFF_LEN];
	int tariff_counts[MAX_ABONENTS] = {0};
	int unique_count = 0;
	
	// Count subscribers by tariff
	for (int i = 0; i < count; i++) {
		int found = 0;
		for (int j = 0; j < unique_count; j++) {
			if (strcmp(abonents[i].tariff, unique_tariffs[j]) == 0) {
				tariff_counts[j]++;
				found = 1;
				break;
			}
		}
		
		if (!found) {
			strcpy(unique_tariffs[unique_count], abonents[i].tariff);
			tariff_counts[unique_count] = 1;
			unique_count++;
		}
	}
	
	// Display results
	for (int i = 0; i < unique_count; i++) {
		printf("Tariff '%s': %d subscribers\n", unique_tariffs[i], tariff_counts[i]);
	}
}

//function for outputting all the bonnets
void print_all_abonents(struct ABON1 abonents[], int count) {
	printf("\nList of all subscribers\n");
	for (int i = 0; i < count; i++) {
		printf("%d. %s | Phone: %s | Date: %d.%d.%d | Tariff: %s | Accrued: %.2f | Balance: %.2f\n",
			   i + 1,
			   abonents[i].fio,
			   abonents[i].phone,
			   abonents[i].connect_date.day,
			   abonents[i].connect_date.month,
			   abonents[i].connect_date.year,
			   abonents[i].tariff,
			   abonents[i].accrued,
			   abonents[i].balance);
	}
}

