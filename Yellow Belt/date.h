#pragma once

class Date {
public:
    Date();
    Date(const int& new_year, const int& new_month, const int& new_day);
    int GetYear();
    int GetMonth();
    int GetDay();
private:
    int year;
    int month;
    int day;
};