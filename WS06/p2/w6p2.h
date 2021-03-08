/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :Namood-e-sehar
	ID     :121979207
	Email  :Namood-e-sahar@myseneca.ca
	Section:NFF
*/
#include <stdio.h>


#define TEST_NEG	-1
#define TEST_ZERO	0
#define TEST_INT	24
#define TEST_DBL	82.5
#define TEST_LBSKG  2.20462
#define TEST_LBSG	2494
#define TEST_LBS	5.5
#define NUM_ITEMS	3
#define SERVING		64
// ------------------  --------------------------------------------------------
// structures
struct CatFoodInfo
{
	int SKU;
	double PRICE;
	double WEIGHT;
	int CALORIES;
};
struct ReportData
{
	int sku;
	double price;
	double wt_pounds;
	int calories;
	double wt_kg;
	int wt_grams;
	double serving;
	double serving_cost;
	double calorie_cost;
};

struct ReportDataNew
{
	struct CatFoodInfo food_info;
	double wt_kg;
	int wt_grams;
	double serving;
	double serving_cost;
	double calorie_cost;
};

int getIntPositive(int* intnumber);
double getDoublePositive(double* Dblnumber);
void openingMessage();
struct CatFoodInfo getCatFoodInfo(int productNum);
void displayCatFoodHeader();
void displayCatFoodData(int SKU, double PRICE, double WEIGHT, int CALORIES);
void start();

double convertLbsKg(double* pounds, double* kgs);
int convertLbsG(double* pounds, int* grams);
void convertLbs(double* pounds, double* kgs, int* grams);
double calculateServings(int serving_size, int product_size, double* servings);
double calculateCostPerServing(double price, double servings, double* cost_per_serving);
double calculateCostPerCal(double price, double calories, double*  cost_per_cal);
struct ReportData calculateReportData(struct CatFoodInfo cat_food_info);
void displayReportHeader(void);
void displayReportData(struct ReportData rpData, int cheapest);
void displayFinalAnalysis(struct CatFoodInfo cat_food_info);


// ----------------------------------------------------------------------------
// defines/macros


// ----------------------------------------------------------------------------
// structures


// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 3. Opening Message (include the number of products that need entering)


// 4. Get user input for the details of cat food product


// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg


// 9. convert lbs: g


// 10. convert lbs: kg / g


// 11. calculate: servings based on gPerServ


// 12. calculate: cost per serving


// 13. calculate: cost per calorie


// 14. Derive a reporting detail record based on the cat food product data


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table


// 17. Display the findings (cheapest)


// ----------------------------------------------------------------------------

// 7. Logic entry point 

#pragma once
