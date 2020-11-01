#include <stdio.h>

static char daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day){
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(i = 1; i < month; i++){
        day += daytab[leap][i];
    }
    return day;
}

void month_year(int year, int yearday, int *pmonth, int *pday){
    int i, leap;
    
    leap = year%4 == 0 && year %100 != 0 || year%400 == 0;

    for(i = 1; yearday > daytab[leap][i]; i++){
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}

int main(){
    int month = 4;
    int day = 15;
    int year = 2020;
    
    int yearday = day_of_year(year, month, day);
    month_year(year, yearday, &month, &day);

    printf("%d.%d is %d day of year %d\n", month, day, yearday, year);
    printf("%d is %d.%d of year %d\n", yearday, month, day, year);
    
    return 0;
}