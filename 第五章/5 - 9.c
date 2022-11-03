int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *p;
   
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while(--month)
        day += *++p;
    return day;
}
 
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while(yearday > *++p)
        yearday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
