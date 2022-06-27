#include "database.h"
#include "date.h"

void Database::Add(const Date& date, const string& event) {
    DB[date].insert(event);
}

bool Database::DeleteEvent(const Date& date, const string& event) {
    if (DB[date].find(event) == DB[date].end()) {
        return false;
    }
    else {
        DB[date].erase(event);
        return true;
    }
}

inline int Database::DeleteDate(const Date& date) {
    int N;
    N = DB[date].size();
    DB.erase(date);
    return N;
}

inline void Database::Find(const Date& date) const {
    if (DB.find(date) != DB.end()) {
        for (const auto& i : DB.at(date)) {
            cout << i << endl;
        }
    }
}

inline void Database::Print() const {
    for (const auto& item : DB) {
        for (const auto& i : DB.at(item.first)) {
            cout << item.first << " " << i << endl;
        }
    }
}
