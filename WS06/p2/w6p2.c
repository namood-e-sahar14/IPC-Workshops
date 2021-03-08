/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Namood-e-sehar
	ID     : 121979207
	Email  :Namood-e-sahar@myseneca.ca
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "w6p2.h"


// System Libraries


// User Libraries

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	int intA, num;
	num = 1;

	while (num == 1)
	{
		scanf("%d", &intA);
		if (intA < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else {
			num = 0;
		}
	}

	if (number != NULL) {
		*number = intA;
	}

	return intA;
}

double getDoublePositive(double* number)
{
	double dblA;
	int num = 1;
	while (num == 1)
	{
		scanf("%lf", &dblA);
		if (dblA <= 0.0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else {
			num = 0;
		}
	}

	if (number != NULL) {
		*number = dblA;
	}

	return dblA;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage()
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\nNOTE: A 'serving' is %dg\n", NUM_ITEMS, SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int productIndex)
{
	struct CatFoodInfo info;

	printf("\nCat Food Product #%d\n", productIndex + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	info.SKU = getIntPositive(&info.SKU);
	printf("PRICE         : $");
	info.PRICE = getDoublePositive(&info.PRICE);
	printf("WEIGHT (LBS)  : ");
	info.WEIGHT = getDoublePositive(&info.WEIGHT);
	printf("CALORIES/SERV.: ");
	info.CALORIES = getIntPositive(&info.CALORIES);

	return info;

}

// 5. Display the formatted table header
void displayCatFoodHeader()
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double price, double weight, int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calories);
}




// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(double* pounds, double* kgs)
{
	double kgReturn = 0;
	kgReturn = *pounds / TEST_LBSKG;
	if (kgs != NULL) {
		*kgs = kgReturn;
	}
	return kgReturn;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(double* pounds, int* grams)
{
	double inKgs;
	int grReturn;

	convertLbsKg(pounds, &inKgs);
	grReturn = inKgs * 1000;

	if (grams != NULL) {
		*grams = grReturn;
	}

	return grReturn;
}

// 10. convert lbs: kg and g
void convertLbs(double* pounds, double* kgs, int* grams)
{
	double inKgs;
	double kgReturn = 0;
	int grReturn;

	kgReturn = convertLbsKg(pounds, &inKgs);
	grReturn = inKgs * 1000;

	if (kgs != NULL) {
		*kgs = kgReturn;
	}

	if (grams != NULL) {
		*grams = grReturn;
	}

}

// 11. calculate: servings based on gPerServ
double calculateServings(int serving_size, int product_size, double* servings)
{
	*servings = product_size / serving_size;
	return *servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(double product_price, double servings, double* cost_per_serving)
{
	*cost_per_serving = product_price /  servings;     
	return *cost_per_serving;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(double product_price, double calories, double* cost_per_cal)
{
	*cost_per_cal = product_price / calories;          
	return *cost_per_cal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cat_food_info)
{
	struct ReportData rpData;

	rpData.sku = cat_food_info.SKU;
	rpData.price = cat_food_info.PRICE;
	rpData.wt_pounds = cat_food_info.WEIGHT;
	rpData.calories = cat_food_info.CALORIES;

	convertLbsKg(&rpData.wt_pounds, &rpData.wt_kg);
	convertLbsG(&rpData.wt_pounds, &rpData.wt_grams);

	calculateServings(SERVING, rpData.wt_grams, &rpData.serving);
	calculateCostPerServing(rpData.price,rpData.serving, &rpData.serving_cost);
	calculateCostPerCal(rpData.price, rpData.calories, &rpData.calorie_cost);
	
	return rpData;
}

/*struct ReportDataNew calculateReportDataNew(struct CatFoodInfo cat_food_info)
{
	struct ReportDataNew rpData;

	rpData.food_info = cat_food_info;
	
	convertLbsKg(&rpData.food_info.WEIGHT, &rpData.wt_kg);
	convertLbsG(&rpData.food_info.WEIGHT, &rpData.wt_grams);

	calculateServings(SERVING, rpData.wt_grams, &rpData.serving);
	calculateCostPerServing(rpData.food_info.PRICE,rpData.serving, &rpData.serving_cost);
	calculateCostPerCal(rpData.food_info.PRICE, rpData.food_info.CALORIES, &rpData.calorie_cost);
	
	return rpData;
}*/
// 15. Display the formatted table header for the analysis results


void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(struct ReportData rpData, int cheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rpData.sku, rpData.price, rpData.wt_pounds, rpData.wt_kg, rpData.wt_grams, rpData.calories, rpData.serving, rpData.serving_cost, rpData.calorie_cost);

	if (cheapest == 1) {
		printf(" ***\n");
	}
	else {
		printf("\n");
	}
}

/*void displayReportDataNew(struct ReportDataNew rpData, int cheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rpData.food_info.SKU, rpData.food_info.PRICE, rpData.food_info.WEIGHT, rpData.wt_kg, rpData.wt_grams, rpData.food_info.CALORIES, rpData.serving, rpData.serving_cost, rpData.calorie_cost);

	if (cheapest == 1) {
		printf(" ***\n");
	}
	else {
		printf("\n");
	}
}*/

// 17. Display the findings (cheapest)

void displayFinalAnalysis(struct CatFoodInfo cat_food_info)
{
	printf("\n\nFinal Analysis");
	printf("\n--------------");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n SKU:%d price: $%lf\n\nHappy shopping!", cat_food_info.SKU, cat_food_info.PRICE);

}
// ----------------------------------------------------------------------------



// 7. Logic entry point

void start()
{
	struct CatFoodInfo items[NUM_ITEMS];

	openingMessage();

	int i = 0;
	for (i = 0; i < NUM_ITEMS; i++)
	{
		items[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < NUM_ITEMS; i++)
	{
		displayCatFoodData(items[i].SKU, items[i].PRICE, items[i].WEIGHT, items[i].CALORIES);
	}
	
	// Part 2

	displayReportHeader();

	struct ReportData rptDataItems[NUM_ITEMS];
	int cheapest_index;
	double min_price;

	for (i = 0; i < NUM_ITEMS; i++)
	{
		if (i == 0 || items[i].PRICE < min_price) {
			min_price = items[i].PRICE;
			cheapest_index = i;
		}

		struct ReportData rptData = calculateReportData(items[i]);

		rptDataItems[i] = rptData;

	}

	int cheapest;
	for (i = 0; i < NUM_ITEMS; i++)
	{
		cheapest = 0;
		if (i == cheapest_index) {
			cheapest = 1;
		}
		displayReportData(rptDataItems[i], cheapest);
	}

	displayFinalAnalysis(items[cheapest_index]);

}
