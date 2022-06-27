#pragma once

#include <map>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);
    void Find(const Date& date) const;
    void Print() const;
private:
    map <Date, set<string>> DB;
};