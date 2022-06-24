#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <cstdint>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

const Date ConvertStringToDate(const string& date_str) {
	Date date{};
	auto first_it = date_str.begin(), second_it = date_str.begin();
	while (second_it != date_str.end()) {
		if (first_it == date_str.begin() && *second_it == '-') {
			string year = { first_it,second_it };
			date.year = stoi(year);
			first_it = second_it;
		}
		else if (*first_it == '-' && *second_it == '-') {
			string month = { first_it + 1,second_it };
			date.month = stoi(month);
			first_it = second_it;
		}
		++second_it;
	}
	if (*first_it == '-' && second_it == date_str.end()) {
		string day = { first_it + 1,second_it };
		date.day = stoi(day);
	}
	//cout << date.year << "-" << date.month << "-" << date.day << endl;
	return date;
}

void ForCheck(const string& str) {
	Date date = ConvertStringToDate(str);
	cout << endl << date.year << endl
		<< date.month << endl
		<< date.day << endl << endl;
}

const int ConvertDateToIndex(const Date& date) {
	int index = 0;
	vector<int> days_in_month = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	index = (date.year - 1700) * 365 + (date.year - 1700) / 4 + 1;
	if (date.year == 1700 || date.year % 4 == 0) {
		if (date.month <= 2) {
			--index;
		}
	}
	if (date.month != 1) {
		for (int i = 0; i < date.month - 1; ++i) {
			index += days_in_month[i];
		}
		index += date.day;
	}
	else {
		index += date.day;
	}
	return index;
}

int main() {
	cout.precision(25);
	//cout << ConvertDateToIndex(ConvertStringToDate("2000-01-01")) << endl; //1 
	//cout << ConvertDateToIndex(ConvertStringToDate("2000-02-02")) << endl; //33 +
	//cout << ConvertDateToIndex(ConvertStringToDate("2000-03-20")) << endl; //80 +
	//cout << ConvertDateToIndex(ConvertStringToDate("2001-02-15")) << endl; //412 - 
	//cout << ConvertDateToIndex(ConvertStringToDate("2099-12-31")) << endl; //36525	
	auto END = ConvertDateToIndex(ConvertStringToDate("2099-12-31"));
	vector<uint64_t> money(END);
	vector<uint64_t> par_sum(END);
	size_t query_num_1;
	cin >> query_num_1;
	for (size_t i = 0; i < query_num_1; ++i) {
		string date;
		cin >> date;
		Date d_ = ConvertStringToDate(date);
		auto index = ConvertDateToIndex(d_);
		uint64_t value;
		cin >> value;
		money[index] += value;		
	}
	//partial_sum(money.begin(), money.end(), par_sum.begin());
	size_t query_num_2;
	cin >> query_num_2;
	for (size_t i = 0; i < query_num_2; ++i) {
		string date_from, date_to;
		cin >> date_from >> date_to;
		Date from = ConvertStringToDate(date_from);
		Date to = ConvertStringToDate(date_to);
		auto index_from = ConvertDateToIndex(from);
		auto index_to = ConvertDateToIndex(to);	
		/*if (index_from > 0) {
			cout << par_sum[index_to] - par_sum[index_from - 1] << endl;
		}
		else {
			cout << par_sum[index_to] << endl;
		}*/
		partial_sum(money.begin() + index_from, money.begin() + index_to + 1, par_sum.begin() + index_from);
		cout << par_sum[index_to] << endl;
		/*partial_sum(money.begin() + index_from, money.begin() + index_to + 1,
			std::ostream_iterator<int>(std::cout, " "));*/
		//cout << accumulate(money.begin() + index_from, money.begin() + index_to + 1, 0.) << '\n';
	}
	return 0;
}