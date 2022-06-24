#include <exception>
#include <sstream>
#include "phone_number.h"
//#include "tests_for_class_PhoneNumber.h"

PhoneNumber::PhoneNumber(const string& international_number) {
	stringstream stream(international_number);
	if (stream.peek() != '+') {
		throw invalid_argument("invalid_argument");
	}
	stream.ignore(1);
	getline(stream, country_code_, '-');
	getline(stream, city_code_, '-');
	getline(stream, local_number_, '\n');
	if (local_number_.empty()) {
		throw invalid_argument("invalid_argument");
	}
}

string PhoneNumber::GetCountryCode() const{
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const{
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

//int main() {
//	TestRunner tr;
//	tr.RunTest(AllTests, "AllTest");	
//	return 0;
//}