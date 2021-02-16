/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   :Namood-e-sehar
	ID     121979207
	Email  :namood-e-sehar	
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#define wishlist 10

int main()
{
	const double min_income = 500.00;
	const double max_income = 400000.00;
	const double item_min_cost = 100;
	const int item_min_prio = 1;
	const int item_max_prio = 3;
	const char finance_yes = 'y';
	const char finance_no = 'n';

	double item_cost[wishlist];
	int item_prio[wishlist];
	char item_finance[wishlist];

	double monthly_income = 0;
	int items = 0;
	double item_cost_summary = 0;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	int go = 1;
	while (go == 1)
	{
		printf("Enter your monthly NET income: $");
		scanf(" %lf", &monthly_income);

		if (monthly_income < min_income)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		if (monthly_income > max_income)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
		if (monthly_income >= min_income && monthly_income <= max_income)
		{
			go = 0;
		}
	}
	go = 1;
	while (go == 1)
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf(" %d", &items);

		if (items < 1 || items > wishlist)
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
		printf("\nItem-%d Details:\n", (i + 1));

		// while loop for cost

		go = 1;
		while (go == 1)
		{
			printf("   Item cost: $");
			scanf(" %lf", &item_cost[i]);
			if (item_cost[i] < item_min_cost)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
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
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &item_prio[i]);

			if (item_prio[i] < item_min_prio || item_prio[i] > item_max_prio)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
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
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &item_finance[i]);
			if (item_finance[i] != finance_yes && item_finance[i] != finance_no)
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

			if (item_finance[i] == finance_yes || item_finance[i] == finance_no)
			{
				go = 0;
			}
		}

	}
	// now print the result of the item
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < items; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, item_prio[i], item_finance[i], item_cost[i]);
		item_cost_summary += item_cost[i];
	}
	printf("---- -------- -------- -----------\n");

	printf("                      $%11.2lf\n\n", item_cost_summary);

	// Part 2 starts here
	const int min_selection = 0;
	const int max_selection = 2;
	int selection, prio_filter, prio_filter_finance_note;
	int tot_months, forecast_years;
	double forecast_months, prio_filter_cost_summary;

	//loop for selection
	int prog = 1;
	while (prog == 1)
	{
		prio_filter_cost_summary = 0;
		prio_filter_finance_note = 0;

		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);

		if (selection < min_selection || selection > max_selection)
		{
			printf("\nERROR: Invalid menu selection.\n\n");
		}
		if (selection == 1)
		{
			printf("\n====================================================\n");
			//tot_months = ceil(item_cost_summary / monthly_income);
			//tot_months = (item_cost_summary / monthly_income) + (((int)item_cost_summary % (int)monthly_income) != 0);
			tot_months = (item_cost_summary + monthly_income - 1) / monthly_income;
			forecast_years = (int)(tot_months / 12);
			forecast_months = tot_months % 12;

			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", item_cost_summary);
			printf("Forecast: %d years, ", forecast_years);
			printf("%.0lf months\n", forecast_months);

			//loop for financing
			for (i = 0; i < items; i++)
			{
				if (item_finance[i] == 'y')
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
			printf("====================================================\n\n");
					break;
				}
			}
		}
		if (selection == 2)
		{
			// while loop for priority
			go = 1;
			while (go == 1)
			{
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf(" %d", &prio_filter);

				if (prio_filter < item_min_prio || prio_filter > item_max_prio)
				{
					printf("ERROR: Value must be between 1 and 3\n");
				}
				if (prio_filter >= item_min_prio && prio_filter <= item_max_prio)
				{

					// filter cost summary for given priority
					for (i = 0; i < items; i++)
					{
						if (item_prio[i] == prio_filter)
						{
							prio_filter_cost_summary = prio_filter_cost_summary + item_cost[i];

							if (item_finance[i] == 'y')
							{
								prio_filter_finance_note = 1;
							}
						}
					}

					printf("\n====================================================\n");
					
					tot_months = (prio_filter_cost_summary + monthly_income - 1) / monthly_income;
					
					forecast_years = (int)(tot_months / 12);
					forecast_months = tot_months % 12;

					printf("Filter:   by priority (%d)\n", prio_filter);
					printf("Amount:   $%.2lf\n", prio_filter_cost_summary);
					printf("Forecast: %d years, ", forecast_years);
					printf("%.0lf months\n", forecast_months);

					if (prio_filter_finance_note == 1)
					{
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n");
					printf("====================================================\n\n");
					}
					if (prio_filter_finance_note != 1)
					{
					printf("====================================================\n\n");
					}break;
				}
			}
		}
		if (selection == 0)
		{
			printf("\nBest of luck in all your future endeavours!\n");
			prog = 0;
		}
	}

	return 0;
}

