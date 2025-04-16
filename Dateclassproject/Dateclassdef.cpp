#include "Date_Header.h"
#include <sstream>
#include <iostream>
using namespace std;


//Date-Constructor
//inputs=values for the month, day, and year.
//output=none
//preconditions=none. 
//postcondition=The date is stored as three integers using the values
//for month, day, and year passed in as parameters.
Date::Date(int m, int d, int y) {

    setDate(m, d, y);
}

//setDate-This function sets the date making sure that the month integer 
//is between 1 and 12, that the day integer is between 1 and the 
//last day of the month as is correct for that month, and the year
//is a positive integer.
//inputs=positive integers for the month, day and year
//output=none
//preconditions=the date must first be created by the constructor
//postcondition=if the inputs for month, day, and year are all valid,
//the date is stored; otherwise, a brief error message is printed 
//and the default date of 1/1/1900 is stored.
void Date::setDate(int m, int d, int y) {

    if (m < 1 || m > 12) {
        cout << "Month invalid";
        month = 1;
        day = 1;
        year = 1900;
    }
    else if (d < 1 || d > getLastDay(m, y)) {
        cout << "Day invalid";
        month = 1;
        day = 1;
        year = 1900;
    }
    else if (y < 1) {
        cout << "Year invalid";
        month = 1;
        day = 1;
        year = 1900;
    }
    else {
        month = m;
        day = d;
        year = y;
    }
}



// overloaded isLeapYear function-Evaluates if the input year is a leap year.
//inputs=year to be evaluated
//output=returns true if the input year is a leap year, false otherwise.
//preconditions=the date must first be created by the constructor.
//postcondition=true or false is returned, depending if the input year is a leap year.
bool Date::isLeapYear(int y) {

    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

//getLastday(int m,y) function-Returns the last day of the month of the input date.
//inputs=the month and year for which the last day of the month 
//should be determined.
//output=none
//preconditions=the date must first be created by one of the constructors,
//(except if the contructor is using this function).
//postcondition=the last day of the month is returned.
int Date::getLastDay(int m, int y) {

    if (m == 2) {
        if (isLeapYear(y))
            return 29;
        else
            return 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

//printDate function-This member function prints the date in the following form: 12/25/2021
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the date has been printed to the returned string.
string Date::printDate1() {
    ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}

//printDate2 function-This member function prints the date in the following form: December 25, 2021 
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the date has been printed to the returned string.
std::string Date::printDate2() {
    const std::string months[] = { "January", "February", "March", "April", "May", "June",
                                   "July", "August", "September", "October", "November", "December" };
    std::ostringstream oss;
    oss << months[month - 1] << " " << day << ", " << year;
    return oss.str();
}

//printDate3 function-This member function prints the date in the following form: 25 December 2021
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the date has been printed to the returned string.
std::string Date::printDate3() {
    const std::string months[] = { "January", "February", "March", "April", "May", "June",
                                   "July", "August", "September", "October", "November", "December" };
    std::ostringstream oss;
    oss << day << " " << months[month - 1] << " " << year;
    return oss.str();
}