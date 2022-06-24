#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

const Date ConvertStringToDate(const string& date_str) {
	Date date;
	auto first_it = date_str.begin(), second_it = date_str.begin();
	while (second_it != date_str.end()) {
		if (first_it == date_str.begin() && *second_it == '-') {
			string year = { first_it,second_it};
			date.year = stoi(year);
			cout << date.year << endl; // for show
			first_it = second_it;
		}
		else if (*first_it == '-' && *second_it == '-') {
			string month = { first_it + 1,second_it };
			date.month = stoi(month);
			cout << date.month << endl; // for show
			first_it = second_it;
		}
		++second_it;
	}
	if (*first_it == '-' && second_it == date_str.end()) {
		string day = { first_it + 1,second_it };
		date.day = stoi(day);
		cout << date.day << endl; // for show
	}
	return date;
}

void ForCheck(const string& str) {
	Date date = ConvertStringToDate(str);
	cout << endl << date.year << endl
		<< date.month << endl
		<< date.day << endl << endl;
}

int ConvertDateToIndex(const Date date) {
	int index = 0;
	vector<int> days_in_month = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	index = (date.year - 2000) * 365 + (date.year - 2000) / 4;
	cout << index;
	return index;
}

int main() {
	cout.precision(25);	
	/*ForCheck("2000-02-28");
	ForCheck("2022-03-24");*/
	ConvertDateToIndex(ConvertStringToDate("2037-23-23"));
	/*int query_num;                                  
	cin >> query_num;
	for (int i = 0; i < query_num; ++i) {
		string command, date_from, date_to;
		cin >> command >> date_from >> date_to;	
		Date from = ConvertStringToDate(date_from);
		Date to = ConvertStringToDate(date_to);
		if (command == "Earn") {
			double value;
			cin >> value;
		}
		else {

		}
	}*/
	return 0;
}