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
#define LOG_DAYS 3

int main()
{
	const int JAN = 1;
	const int DEC = 12;

	int log_month, log_year, log_day, valid_morning_ratings, valid_evening_ratings;
	double morning_reading, evening_reading;
	double morning_summary = 0, evening_summary = 0;
	double average_overall, average_morning, average_evening, summary_overall, numofaverage = 2;
		
	printf("General Well-being Log\n");
	printf("======================\n");

	char having_error = 'y';
	while (having_error == 'y')
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		 scanf("%d %d", &log_year, &log_month);

		 if (log_year < MIN_YEAR || log_year > MAX_YEAR)
		 {
			 printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		 }
		if (log_month < JAN || log_month > DEC)
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
			}
		 
		else {
			having_error = 'n';
		}
	}

	char log_month_name[4];
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
	case 11:
		strcpy(log_month_name, "NOV");
		break;
	case 12:
		strcpy(log_month_name, "DEC");
		break;
	default:
		break;
	}

	printf("\n*** Log date set! ***\n");

	for (log_day = 1; log_day <= LOG_DAYS; log_day++)
	{
		printf("\n%d-%s-0%d\n", log_year, log_month_name, log_day);

		valid_morning_ratings = 1;
		while (valid_morning_ratings == 1)
		{
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morning_reading);
			if (morning_reading < 0.0 || morning_reading > 5.0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
			else {
				valid_evening_ratings = 1;
				while (valid_evening_ratings == 1)
				{
					printf("   Evening rating (0.0-0.5): ");
					scanf("%lf", &evening_reading);
					if (evening_reading < 0.0 || evening_reading > 5.0)
					{
						printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					}
					else {

						morning_summary = morning_summary + morning_reading;
						evening_summary = evening_summary + evening_reading;
						
						valid_evening_ratings = 0;
						valid_morning_ratings = 0;
					
					}
				}
			}

		}

	}

	printf("\nSummary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", morning_reading);
	printf("Evening total rating: %.3lf\n", evening_summary);
	printf("----------------------------");

	summary_overall = morning_summary + evening_summary;
	printf("\nOverall total rating: %.3lf\n", summary_overall);
	
	average_morning = morning_summary / LOG_DAYS;
	average_evening = evening_summary / LOG_DAYS;

	printf("\nAverage morning rating: %.1lf\n", average_morning);
	printf("Average evening rating: %.1lf\n", average_evening);
	printf("---------------------------\n");
	average_overall = average_morning + average_evening /numofaverage;
	printf("Average overall rating: %.1lf\n", average_overall);

	return 0;

}