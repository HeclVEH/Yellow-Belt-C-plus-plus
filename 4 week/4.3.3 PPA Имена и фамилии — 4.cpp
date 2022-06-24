#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
    auto it = names.upper_bound(year);
    string name;
    if (it != begin(names)) {
        name = (--it)->second;
    }
    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // �������� ���� ��������� ����� �� first_name � ��� year
        name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // �������� ���� ��������� ������� �� last_name � ��� year
        surname[year] = last_name;
    }
    string GetFullName(int year) {
        auto first = FindNameByYear(name, year);
        auto second = FindNameByYear(surname, year);
        if (empty(first) && empty(second)) {
            return "Incognito";
        }
        else if (empty(first)) {
            return second + " with unknown first name";
        }
        else if (empty(second)) {
            return first + " with unknown last name";
        }
        else {
            return first + " " + second;
        }
    }        
private:
    // ��������� ����
    map<int, string> name, surname;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
