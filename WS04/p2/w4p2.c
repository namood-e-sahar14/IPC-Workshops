/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   :Namood-e-sehar
	ID     1121979207
	Email  :namood-e-sehar	
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define wishlist 100

int main()
{
	const double min_income = 500;
	const double max_income = 400000.00;
	const double item_min_cost = 100;
	const int item_min_prio = 1;
	const int item_max_prio = 3;
	const char finance_yes = 'y';
	const char finance_no = 'n';

	double item_cost[wishlist];
	int item_prio[wishlist];
	char item_finance[wishlist];

	double monthly_income;
	int items;
	double item_cost_summary = 0;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	
	int go = 1;
	while (go == 1)
	{
		printf("Enter your monthly NET income:");
		scanf("%lf", &monthly_income);

		if (monthly_income < min_income)
		{
			printf("ERROR: You must have a consistent monthly income of atleast $500.00\n");
		}
		if (monthly_income > max_income)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400,000.00\n");
		}

		if (monthly_income >= min_income && monthly_income <= max_income)
		{
			go = 0;
		}
	}
	
	go = 1;
	while (go == 1)
	{
		printf("Enter your wishlist:");
		scanf("%d", &items);

		if (items < 1 && items > wishlist)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}

		if (items >= 1 && items <= wishlist)
		{
			go = 0;
		}
	}
	
	int i;
	for (i = 0; i < items; i++)
	{
		printf("Item-%d Details: \n", (i+1));

		// while loop for cost
		
		go = 1;
		while (go == 1)
		{
			printf("Item cost: $");
			scanf("%lf", &item_cost[i]);

			if (item_cost[i] < item_min_cost)
			{
				printf("ERROR: Minimum cost should be $100.00\n");
			}

			if (item_cost[i] >= item_min_cost)
			{
				go = 0;
			}
		}

		
		// while loop for priority
		go = 1;
		while (go == 1)
		{
			printf("How important is it to you? [1=must have, 2=important, 3=want]:");
			scanf("%d", &item_prio[i]);

			if (item_prio[i] < item_min_prio || item_prio[i] > item_max_prio)
			{
				printf("ERROR: Value must be between 1 and 3\n");
			}

			if (item_prio[i] >= item_min_prio && item_prio[i] <= item_max_prio)
			{
				go = 0;
			}
		}

		// while loop for finance
		go = 1;
		while (go == 1)
		{
			printf("Does this item have financing options? [y/n]: ");
			scanf(" %c", &item_finance[i]);

			if (item_finance[i] != finance_yes && item_finance[i] != finance_no)
			{
				printf("ERROR: Must be a lower case 'y' or 'n'\n");
			}

			if (item_finance[i] == finance_yes || item_finance[i] == finance_no)
			{
				go = 0;
			}
		}

	}

	// now print the result of the items
	printf("\nitems prio finance        cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < items; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, item_prio[i], item_finance[i], item_cost[i]);
		item_cost_summary += item_cost[i];
	}
	printf("---- -------- -------- -----------\n");

	printf("                      $%11.2lf\n\n", item_cost_summary);
	
	
//now loop the menu for selection
//int selection[items];
//const min_selection = 0;
//const max_selection = 2;
//go = 1;
//while (go == 1)
//{
//	printf("How do you want to forecast your wish list?\n1. All items (no filters)\n2. By priority\n0. Quit/Exit\nSelection: ");
//	scanf("%d", &selection[i]);
//
//	if (selection[i] < min_selection && selection[i] > max_selection)
//	{
//		printf("ERROR: Invalid menu selection.\n");
//	}
//
//	if (selection[i] >= min_selection && selection[i] < max_selection)
//	{
//		go = 0;
//	} 
//}
// now print the result of the selections
 

	
	printf("Best of luck in all your future endeavours!\n");
	return 0;

}