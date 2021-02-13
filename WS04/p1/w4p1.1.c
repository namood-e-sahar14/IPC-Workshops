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
#define wishlist 10

int main()
{
	const double min_income = 500;
	const double max_income = 400000.00;
	double monthly_income;
	double cost, ncost = 0, nprio=0, nfinance=0;
	int prio, n;
	char finance;

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

	int items;
	go = 1;
	while (go == 1)
	{
		printf("Enter your wishlist:");
		scanf("%d", &n);

		if (n < wishlist && n > wishlist)
		{
			items[nitems++] = n;
				printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}

		if (items >= wishlist && items <= wishlist)
		{
			go = 0;
		}
	

	double cost[wishlist];
	int prio[wishlist];
	char finace[wishlist];


	const double min_cost = 100;

	int i;
	for (i = 0; i < items; i++)
	{
		printf("Item-%d Details: \n", (i + 1));

		// while loop for cost

		go = 1;
		while (go == 1)
		{
			printf("Item cost: $");
			scanf("%lf", &cost[i]);

			if (cost[i] < min_cost)
			{
				printf("ERROR: You must have a consistent monthly income of atleast $500.00\n");
			}

			if (cost[i] >= min_cost)
			{
				go = 0;
			}
		}


		// while loop for priority

		const min_prio = 1;
		const max_prio = 3;
		go = 1;
		while (go == 1)
		{
			printf("How important is it to you? [1=must have, 2=important, 3=want]:");
			scanf("%d", &prio[i]);

			if (prio[i] < min_prio && prio[i] > max_prio)
			{
				printf("ERROR: Value must be between 1 and 3\n");
			}

			if (prio[i] >= min_prio && prio[i] < max_prio)
			{
				go = 0;
			}
		}

		// while loop for finance

		const char finance_yes = 'y';
		const char finance_no = 'n';
		go = 1;
		while (go == 1)
		{
			printf("Does this item have financing options? [y/n]: $");
			scanf("%s", &finance[i]);

			if (finance[i] == finance_yes && finance[i] == finance_no)
			{
				printf("ERROR: Must be a lower case 'y' or 'n'\n");
			}

			if (finance[i] != finance_yes && finance[i] != finance_no)
			{
				go = 0;
			}
		}

	}

	// now print the result of the items
	printf("Item\tPriority\tFinance\tCost");

	double cost_summary = 0;
	for (i = 1; i <= items; i++) {
		printf("%d\t", (i + 1));
		printf("%d\t", prio[i]);
		printf("%s\t", finance[i]);
		printf("%.2lf\n", cost[i]);
	}

	cost_summary = cost_summary + cost[i];


	printf("Item\tPriority\tFinance\tCost");
	printf("---- -------- -------- -----------\n");
	printf("%3d  %5d   %5c    %11.2lf\n");
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n");
	printf("Best of luck in all your future endeavours!\n");

	return 0;
}