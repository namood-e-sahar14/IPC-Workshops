/*
    ==================================================
    Workshop #2 (Part-2):
    ==================================================
    Name   :Namood-e-sehar
    ID     :121979207
    Email  :namood-e-sahar@myseneca.ca
    Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int toonies, // this will store the number of toonies, loonies,quarter, dime, nickle and penny of the amount
        loonies,
        quarter,
        dime,
        nickle;

    double penny;
    double amount, // this will store amount entered by user and service and remaining 
        remaining,
        service;

    // Prompt user for the input
    printf("Change Maker Machine \n");
    printf("==================== \n");
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &amount);

    // calculate 5% of the amount
    service = 0.50;
    printf("Service Fee (5.0 percent): $%.2lf \n", service);

    // subtract the 5% chargee from  the amount
    amount = amount - service;
    printf("Balance to dispense: $%.2lf \n", amount);
   
    // Calculate Toonies by dividing to 2 and display to user
    toonies = (int)(amount / 2);
    printf("\n\n$2.00 Toonies X %d ", toonies);
    // Calculate remaining by subtracting the total amount of toonies from main amount
    remaining = amount - (toonies * 2);
    printf("(remaining: $%.2lf) \n", remaining);

    // Calculate loonies by dividing to 1 and display to user
    loonies = (int)(remaining / 1);
    printf("$1.00 Loonies X %d ", loonies);
    // Calculate remaining by subtracting the total amount of loonies from remaining 
    remaining = remaining - (loonies * 1);
    printf("(remaining: $%.2lf) \n", remaining);

    // Calculate quarters by dividing to 0.25 and display to user
    quarter = (int)(remaining / 0.25);
    printf("$0.25 Quarters X %d ", quarter);
    // Calculate remaining by subtracting the total amount of quarters from remaining
    remaining = remaining - (quarter * 0.25);
    printf("(remaining: $%.2lf) \n", remaining);

    // Calculate dimes by dividing to 0.10 and display to user
    dime = (int)(remaining / 0.10);
    printf("$0.10 Dimes X %d ", dime);
    // Calculate remaining by subtracting the total amount of dimes from remaining
    remaining = remaining - (dime * 0.10);
    printf("(remaining: $%.2lf) \n", remaining);

    // Calculate nickles by dividing to 0.05 and display to user
    nickle = (int)(remaining / 0.05);
    printf("$0.05 Nikles X %d ", nickle);
    // Calculate remaining by subtracting the total amount of nickles from remaining
    remaining = remaining - (nickle * 0.05);
    printf("(remaining: $%.2lf) \n", remaining);
    
    // Calculate pennies by dividing to 0.01 and display to user
    penny = (remaining / 0.01);
    printf("$0.01 Pennies X %.0lf ", penny);
    // Calculate remaining by subtracting the total amount of pennies from remaining
    remaining = remaining - (penny * 0.01);
    printf("(remaining: $%.2lf) \n", remaining);

    printf("\nAll coins dispensed!\n");

    return 0;

}
