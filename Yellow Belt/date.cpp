#include <string>
#include <stdexcept>
#include <iomanip>
#include <sstream>

#include "date.h"


Date ParseDate(istream& is) {
    string s_year, s_month;

    getline(is, s_year, '-');
    getline(is, s_month, '-');

    int day, month, year;
    is >> day;

    month = stoi(s_month);
    year = stoi(s_year);

    if (day < 1 || day > 31 || month < 1 || month > 12) {
        throw invalid_argument("Invalid date: " + s_year + "-" + s_month + "-" + to_string(day));
    }

    return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year_ << '-';
    os << setfill('0') << setw(2) << date.month_ << '-';
    os << setfill('0') << setw(2) << date.day_;

    return os;
}

bool operator<(const Date& d1, const Date& d2) {
    if (d1.year_ < d2.year_)
        return true;

    if (d1.year_ > d2.year_)
        return false;

    if (d1.month_ > d2.month_)
        return false;

    if (d1.month_ < d2.month_)
        return true;

    return d1.day_ < d2.day_;
}

bool operator==(const Date& d1, const Date& d2) {
    return d1.year_ == d2.year_ && d1.month_ == d2.month_ && d1.day_ == d2.day_;
}

bool operator!=(const Date& d1, const Date& d2) {
    return !(d1 == d2);
}

bool operator<=(const Date& d1, const Date& d2) {
    return (d1 < d2) || (d1 == d2);
}

bool operator>(const Date& d1, const Date& d2) {
    return (d1 != d2) && !(d1 < d2);
}

bool operator>=(const Date& d1, const Date& d2) {
    return (d1 > d2) || (d1 == d2);
}

string Date::tostring() const {
    ostringstream ss; ss << *this;
    return ss.str();
}