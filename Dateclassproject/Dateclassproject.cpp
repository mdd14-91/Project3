#include <iostream>
#include "Date_Header.h"
using namespace std;

//The main function works by testing the constructor, and mutator for valid/invalid dates along with verifying the leap year.
//in addition, it displays the default constructor date.In addition, we test the leap year one last time along with the get dates for
//the day, month and year. And we test the get last day stored function again.
int main() {
    //Test default constructor
    Date defaultDate;
    cout << "Test default constructor: " << defaultDate.printDate1() << endl << endl;

    //Test constructor with valid date
    Date validDate(12, 28, 2021);
    cout << "Test constructor with valid date: " << validDate.printDate1() << endl << endl;

    //Test invalid month 
    cout << "Test constructor with invalid month(14, 2, 1990) : ";
    Date invalidMonth(14, 2, 1999);
    cout << endl << invalidMonth.printDate1() << endl << endl;

    //Test invalid day
    cout << "Test constructor with invalid day (2/33/2009): ";
    Date invalidDay(2, 33, 2009);
    cout << endl << invalidDay.printDate1() << endl << endl;

    //Test invalid month for setDate
    Date invalidMonthSetDate;
    cout << "Test setDate with bad month (14): ";
    invalidMonthSetDate.setDate(14, 1, 2009);
    cout << endl << invalidMonthSetDate.printDate1() << endl << endl;

    //Test invalid day for setDate
    Date invalidDaySetDate;
    cout << "Test setDate with bad day (4, 35, 2009): ";
    invalidDaySetDate.setDate(4, 35, 2009);
    cout << endl << invalidDaySetDate.printDate1() << endl << endl;

    //Test leap year bad date
    cout << "Test for leap year with bad date (2/25/2009): ";
    Date leapYearBadDate(2, 25, 2010);
    cout << endl << leapYearBadDate.printDate1() << endl << endl;

    //Test leap year good date
    Date leapYearGoodDate(2, 29, 1994);
    cout << "Test for leap year with good date (2/29/2004): " << leapYearGoodDate.printDate1() << endl << endl;

    //Test the print formats
    cout << "Test the print formats:" << endl << endl;
    cout << leapYearGoodDate.printDate2() << endl; // February 29, 2008
    cout << leapYearGoodDate.printDate3() << endl << endl; // 29 February 2008

    //Additional tests:
    Date additionalDate(2, 27, 2009);
    cout << "Test getMonth: " << additionalDate.getMonth() << endl;
    cout << "Test getDay: " << additionalDate.getDay() << endl;
    cout << "Test getYear: " << additionalDate.getYear() << endl << endl;

    cout << "Test isLeapYear() of stored date : ";
    if (additionalDate.isLeapYear())
        cout << "stored date is a leap year" << endl << endl;
    else
        cout << "stored date is NOT a leap year" << endl << endl;

    cout << "Test getLastDay() of stored month : ";
    cout << additionalDate.getLastDay() << endl << endl;
}