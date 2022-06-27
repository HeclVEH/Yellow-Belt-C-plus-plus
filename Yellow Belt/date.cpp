#include "date.h"

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(const int& new_year, const int& new_month, const int& new_day) {
    year = new_year;
    month = new_month;
    day = new_day;
}

int Date::GetYear() {
    return year;
}

int Date::GetMonth() {
    return month;
}

int Date::GetDay() {
    return day;
}