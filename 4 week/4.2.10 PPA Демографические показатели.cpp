#include <vector>
#include <iostream>
#include <algorithm>

//using namespace std;
//
//enum class Gender {
//    FEMALE,
//    MALE
//};
//
//struct Person {
//	int age;  // �������
//	Gender gender;  // ���
//	bool is_employed;  // ����� �� ������
//};
//
//// ��� ������ �������, ��� �� ����� ���������� ������ � �������� PrintStats
//template <typename InputIt>
//int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//    if (range_begin == range_end) {
//        return 0;
//    }
//    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//    auto middle = begin(range_copy) + range_copy.size() / 2;
//    nth_element(
//        begin(range_copy), middle, end(range_copy),
//        [](const Person& lhs, const Person& rhs) {
//            return lhs.age < rhs.age;
//        }
//    );
//    return middle->age;
//}

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl; //Median age = 40
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), partition(begin(persons), end(persons),
        [](Person pers) {return pers.gender == Gender::FEMALE; })) << endl;   //Median age for females = 40
    cout << "Median age for males = " << ComputeMedianAge(begin(persons), partition(begin(persons), end(persons),
        [](Person pers) {return pers.gender == Gender::MALE; })) << endl;   //Median age for males = 55
    cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), partition(begin(persons), end(persons),
        [](Person pers) {return (pers.gender == Gender::FEMALE && pers.is_employed == true); })) << endl; //Median age for employed females = 40
    cout << "Median age for unemployed females = " << ComputeMedianAge(begin(persons), partition(begin(persons), end(persons),
        [](Person pers) {return (pers.gender == Gender::FEMALE && pers.is_employed == false); })) << endl;   //Median age for unemployed females = 80
    cout << "Median age for employed males = " << ComputeMedianAge(begin(persons), partition(begin(persons), end(persons),
        [](Person pers) {return (pers.gender == Gender::MALE && pers.is_employed == true); })) << endl;  //Median age for employed males = 55
    cout << "Median age for unemployed males = " << ComputeMedianAge(begin(persons), partition(begin(persons), end(persons),
        [](Person pers) {return (pers.gender == Gender::MALE && pers.is_employed == false); })) << endl;  //Median age for unemployed males = 78
}
 
int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}

//������� �� �������������
void PrintStats(vector<Person> persons) {
    // ����������� ������� ����� � ����������:
    //                  persons
    //                 /      \
    //          females        males
    //         /       \     /      \
    //      empl.  unempl. empl.   unempl.
    auto females_end = partition(
        begin(persons), end(persons), [](const Person& p) {
            return p.gender == Gender::FEMALE;
        }
    );
    auto employed_females_end = partition(
        begin(persons), females_end, [](const Person& p) {
            return p.is_employed;
        }
    );
    auto employed_males_end = partition(
        females_end, end(persons), [](const Person& p) {
            return p.is_employed;
        }
    );

    // ������ ������������ ��� ������ ��������� � ������� ����������
    cout << "Median age = "
        << ComputeMedianAge(begin(persons), end(persons)) << endl;
    cout << "Median age for females = "
        << ComputeMedianAge(begin(persons), females_end) << endl;
    cout << "Median age for males = "
        << ComputeMedianAge(females_end, end(persons)) << endl;
    cout << "Median age for employed females = "
        << ComputeMedianAge(begin(persons), employed_females_end) << endl;
    cout << "Median age for unemployed females = "
        << ComputeMedianAge(employed_females_end, females_end) << endl;
    cout << "Median age for employed males = "
        << ComputeMedianAge(females_end, employed_males_end) << endl;
    cout << "Median age for unemployed males = "
        << ComputeMedianAge(employed_males_end, end(persons)) << endl;
}