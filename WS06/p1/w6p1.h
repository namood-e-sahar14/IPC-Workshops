/*
	==================================================
	Workshop #6 (Part-1):
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
#define num_of_grams   64
#define num_of_items   3
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int SKU;
	double PRICE;
	double WEIGHT;
	int CALORIES;
};

int getIntPositive(int* intnumber);
double getDoublePositive(double* Dblnumber);
void openingMessage();
struct CatFoodInfo getCatFoodInfo(int productNum);
void displayCatFoodHeader();
void displayCatFoodData(int SKU, double PRICE, double WEIGHT, int CALORIES);
void start();
