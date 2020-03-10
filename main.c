/*
    Programm: TagDesJahres
    Author: Florian Pachulleck
    Datum: 28.1.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"



int main()
{

    //Funktionen aufrufen für die ganze Rechnung
    int TagImJahr = day_of_the_year(input_date());

    //Ausgabe
    printf("\nTag im Jahr: %d \n", TagImJahr);


    return 0;
}
