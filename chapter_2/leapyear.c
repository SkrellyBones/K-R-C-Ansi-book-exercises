#include <stdio.h>
int year;
#define CURRENT_YEAR 2025
int main(){

for(year=1900; year<=CURRENT_YEAR; year++){

if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    printf("%d is a leap year\n", year);
else
    printf("%d is not a leap year\n", year);
}
return 0;
}
