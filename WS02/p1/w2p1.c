/*
    ==================================================
    Workshop #2 (Part-1):
    ==================================================
    Name   :Namood-e-sehar
    ID     :121979207
    Email  :namood-e-sahar@myseneca.ca
    Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
    int cents, coins;
    double toonies, // this will store the number of toonies in the amount
        dollars, 
        amount, // this
        loonies, remaining,quarter;

    // Prompt user for the input
    printf("Change Maker Machine \n");
    printf("==================== \n");
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &amount);

    // Calculate Toonies by dividing to 2 and display to user
    toonies = floor(amount / 2);
    printf("\n\n$2.00 Toonies X %.0lf", toonies);
    // Calculate remaining by subtracting the total amount of toonies from main amount
    remaining = amount - (toonies * 2);
    printf("(remaining: $=%.2lf) \n", remaining);

    loonies = floor(remaining / 1);
    printf("$ 1.00 Loonie x =%.0lf ", loonies);
    remaining = remaining - (loonies * 1);
    printf("(remaining: $=%.2lf) \n", remaining);
   
    quarter = floor(remaining / 0.25);
    printf("$ 0.25 quarter x =%.0lf ",quarter);
    remaining = remaining - (quarter *0.25);
    printf("(remaining: $=%.2lf) \n", remaining);
    
    printf("Machine Error! Thankyou for letting me Keep change = $ %.2lf \n", remaining);

 
    return 0;
}
