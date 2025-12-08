#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int day_of_year(int year, int month, int day) {
    int i, leap;
    char *p;
    if (year < 1 || month < 1 || month > 12)
        return -1;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
     p = *(daytab + leap);  
    if (day < 1 || day > *(p + month))
        return -1;
    for (i = 1; i < month; i++)
        day += *(p + i);
    return day;
}
int month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    char *p; 
    if (year < 1 || pmonth == NULL || pday == NULL)
        return -1;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = *(daytab + leap);  // pointer to the row
    if (yearday < 1 || yearday > 365 + leap)
        return -1;
    i = 1;
    while (yearday > *(p + i))
        yearday -= *(p + i++);
    *pmonth = i;
    *pday = yearday;

    return 0;
}
