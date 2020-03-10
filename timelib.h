#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
	int day;
	int month;
	int year;
};

int is_leapyear(int year);
int get_days_for_month(int month, int year);
int day_of_the_year(struct date dateValue);
int exists_date(struct date dateValue);
struct date input_date();



#endif // TIMELIB_H_INCLUDED

