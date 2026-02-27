Author: Mankewich Anhelina, 27.02.2026

#ifndef ABONENT_H
#define ABONENT_H

/*structure and function prototypes used in main.c client,
implementation can be found in abonent.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ABONENTS 12
#define MAX_TARIFF_LEN 20

//connection date structure
struct Date;

//main structure
struct ABON1;

//function for inputting abonents data through console
int input_abonents(struct ABON1 abonents[], int max_size);

//function for comparing abonents by first letters
int compare_abonents(const void *a, const void *b);

//function for sorting abonents in alphabet order
void sort_abonents(struct ABON1 abonents[], int count);

//function for determining whether 10 years passed
int is_more_than_10_years(struct Date connect_date);

//function for adding 10 rub on abonent’s account
void add_bonus(struct ABON1 abonents[], int count);

//function for outputting abonents with negative balance
void print_negative_balance(struct ABON1 abonents[], int count);

//function for outputting number of abonents for each tariff
void print_tariff_stats(struct ABON1 abonents[], int count);

//function for outputting all the bonnets
void print_all_abonents(struct ABON1 abonents[], int count);

#endif
