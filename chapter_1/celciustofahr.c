#include <stdio.h>

int main(){
    float fahr, celcius;
    float upper, lower, step;
    lower = 0;
    upper = 300;
    step = 20;
    
    celcius = lower;

    printf("Celcius\tFarenheight\n");

    while (celcius <=upper){
        fahr = (9.0/5.0)*(celcius) + 32;
        printf("%3.0f\t %6.1f\n",celcius,fahr);
        celcius = celcius + step;
    };

};
