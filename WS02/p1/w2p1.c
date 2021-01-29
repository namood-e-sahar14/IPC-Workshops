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
    int cents, coins, tc, lc, qc;
    double toonies, // this will store the number of toonies in the amount
         
        amount, // this
        loonies, remaining,quarter;

    // Prompt user for the input
    printf("Change Maker Machine \n");
    printf("==================== \n");
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &amount);

    // Calculate Toonies by dividing to 2 and display to user
    toonies = (amount / 2);
   tc = toonies - 0.5;
 
    printf("\n\n$2.00 Toonies X =%d", tc);
    // Calculate remaining by subtracting the total amount of toonies from main amount
    remaining = amount - (tc * 2);
    printf("(remaining: $=%.2lf) \n", remaining);

   
    loonies = (remaining  / 1);
    lc = loonies - 0.5;
    printf("$ 1.00 Loonie x =%d ", lc);
    remaining =remaining - (lc * 1);
    printf("(remaining: $=%.2lf) \n", remaining);
   
    quarter = (remaining / 0.25);
    qc = quarter - 0.5;
    printf("$ 0.25 quarter x =%d ",qc);
    remaining = remaining- (qc *0.25);
    printf("(remaining: $=%.2lf) \n", remaining);
    
    printf("Machine Error! Thankyou for letting me Keep change = $ %.2lf \n", remaining);

 
    return 0;
}
