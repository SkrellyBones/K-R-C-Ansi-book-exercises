#include <stdio.h>
 /* print Fahrenheit-Celsius table */
int main()
 {
    #define LOWER 0
    #define UPPER 300  // symbolic constant name replacements for numbers
    #define STEP  20
 int fahr;
 for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
     printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

//print it in reverse order after
for (fahr = UPPER; fahr >=LOWER; fahr = fahr-STEP)
    printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr-32));
 } 

