#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

//Testet ob das eingegebene Jahr ein Schaltjahr ist
int is_leapyear(int year)
{
    if(year < 1582)
    {
        return -1;
    }

    if (year % 400 == 0)                        //Abfrage ob das Jahr genau durch 400 teilbar ist. Ja = Schaltjahr.
    {
        return 1;
    }
    else
    {
        if (year % 100 == 0)                     //Abfrage ob das Jahr genau durch 100 teilbar ist. Ja = kein Schaltjahr.
        {
            return 0;
        }
        else
        {
            if (year % 4 == 0)                  //Abfrage ob das Jahr genau durch 4 teilbar ist. Ja = Schaltjahr.
            {
                return 1;
            }
            else                                //Durch nicht teilbar daraus folgt : kein Schaltjahr.
            {
                return 0;
            }
        }
    }

    return 0;
}

//Checkt ob Monat existiert und wievuele Tage er hat
int get_days_for_month(int month, int year)
{
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(is_leapyear(year))
    {
        tage[1] = 29;
    }

    if(month < 0 || month > 13)
    {
        return -1;
    }
    else
    {
        return tage[month];
    }
}

//Rechnet den wievielten Tag im Jahr der eingegebene Tag ist
int day_of_the_year(struct date dateValue)
{
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(is_leapyear(dateValue.year))
    {
        tage[1] = 29;
    }

    int AnzahlTag = dateValue.day;
    int i = 0;
    while(i < dateValue.month - 1)
    {
        AnzahlTag = AnzahlTag + tage[i];
        i++;
    }

    return AnzahlTag;
}

//checkt ob das eingegebene Datum existiert
int exists_date(struct date dateValue)
{
     int monthdays = get_days_for_month(dateValue.month, dateValue.year);
    if(monthdays == -1 || dateValue.year > 2400 || dateValue.year < 1582 || dateValue.day < 1 || dateValue.day> monthdays)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Eingabe von Tag, Monat, Jahr
struct date input_date()
{
    struct date dateValue;

    do
    {
      printf("Tag:");
        scanf("%d", &dateValue.day);
        printf("Monat:");
        scanf("%d", &dateValue.month);
        printf("Jahr:");
        scanf("%d", &dateValue.year);
    }
    while(!exists_date(dateValue));

    return dateValue;
}

