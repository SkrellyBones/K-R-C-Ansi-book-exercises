#include <stdio.h>

int main(){

    float fahr, celcius; //declare the type of the variable as float
    float lower, upper, step;

    lower = 0; //assign the variable to a value
    upper = 300;
    step = 20;

    fahr = lower;
printf("Farenheight\tCelcius\n");
    while (fahr<=upper){
        celcius = (5.0/9.0)*(fahr-32.0); //celcius to farenheit formula
        printf("%3.0f \t \t %6.1f\n",fahr,celcius); //how to insert variable into print, %d is for an integer
        //%f is for a float, the numbers are for width alignment.
        fahr = fahr+step;
    };
/*Among others, printf also recognizes %o for octal, %x for hexadecimal, %c for character, %s
for character string and %% for itself. 
*/
};