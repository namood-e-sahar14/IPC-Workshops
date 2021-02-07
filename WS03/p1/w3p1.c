/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Namood-e-sehar
	ID     :121979207
	Email  :Namood-e-sahar@myseneca.ca
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MIN_YEAR 2010	
#define MAX_YEAR 2021

int main()
{
	const int JAN = 1;
	const int DEC = 12;

	int log_month, log_year;
	
	printf("General Well_being Log\n");
	printf("======================\n");

	int execute = 1;
	int execution_error;
	while (execute == 1)
	{
		execution_error = 0;
		printf("Set the year and month for the well-being log (YYYY MM): ");
		int inputs = scanf("%d %d", &log_year, &log_month);

		if (log_year < MIN_YEAR || log_year > MAX_YEAR)
		{
			printf("ERROR: The year must be between 2010 and 2021 inclusive\n");
			execution_error = 1;
		}
		
		if (log_month < JAN || log_month > DEC)
		{
			printf("ERROR: Jan.(1) - Dec.(12)\n");
			execution_error = 1;
		}
		
		if (execution_error == 0) {
			execute = 0;
		}
	}

	char log_month_name[4] = "DEC";
	switch (log_month)
	{
		case 1:
			strcpy(log_month_name, "JAN");
			break;
		case 2:
			strcpy(log_month_name, "FEB");
			break;
		case 3:
			strcpy(log_month_name, "MAR");
			break;
		case 4:
			strcpy(log_month_name, "APR");
			break;
		case 5:
			strcpy(log_month_name, "MAY");
			break;
		case 6:
			strcpy(log_month_name, "JUN");
			break;
		case 7:
			strcpy(log_month_name, "JUL");
			break;
		case 8:
			strcpy(log_month_name, "AUG");
			break;
		case 9:
			strcpy(log_month_name, "SEP");
			break;
		case 10:
			strcpy(log_month_name, "OCT");
			break;
		case 11:
			strcpy(log_month_name, "NOV");
			break;
		case 12:
			strcpy(log_month_name, "DEC");
			break;
		default:
			break;
	}

	printf("\n\n*** Log date set! ***\n\n");
	printf("Log starting date: %d-%s-0%d\n\n", log_year, log_month_name, 1);
		
	return 0;

}