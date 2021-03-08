/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Namood-e-sehar
	ID     : 121979207
	Email  :Namood-e-sahar@myseneca.ca
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "w6p1.h"


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
		} else {
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
	//printf("===========================\n");
	//printf("Starting Main Program Logic\n");
	//printf("======================\n");
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\nNOTE: A 'serving' is %dg\n", num_of_items, num_of_grams);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int productIndex)
{
	struct CatFoodInfo info;

	printf("\nCat Food Product #%d\n", productIndex+1);
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

// 7. Logic entry point
void start()
{
	struct CatFoodInfo items[num_of_items];
	
	openingMessage();
	
	int i = 0;
	for (i = 0; i < num_of_items; i++)
	{
		items[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();
	
	for (i = 0; i < num_of_items; i++)
	{
		displayCatFoodData(items[i].SKU, items[i].PRICE, items[i].WEIGHT, items[i].CALORIES);
	}
}
