#pragma once

#include <iostream>

using namespace std;

class Date {
public:
    Date() : 
        year_(1), month_(1), day_(1) 
    {}
    Date(int year, int month, int day) : 
        year_(year), month_(month), day_(day) 
    {}
    const int year_, month_, day_;
    string tostring() const;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);
bool operator<(const Date& d1, const Date& d2);
bool operator==(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);
bool operator<=(const Date& d1, const Date& d2);
bool operator>(const Date& d1, const Date& d2);
bool operator>=(const Date& d1, const Date& d2);