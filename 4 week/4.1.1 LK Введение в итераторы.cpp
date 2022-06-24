#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Lang {
	string name;
	int age;
};

int main() {
	vector<Lang> langs = {
		{"Pytnon", 26}, 
		{"C++", 34}, 
		{"C", 45}, 
		{"Java", 22}, 
		{"C#", 17} };
	auto result = find_if(
		begin(langs), end(langs),
		[](const Lang& lang) {
			return lang.name[0] == 'D'; 
		});
	cout << begin(langs)->name << " "
		<< begin(langs)->age << endl;
	/*if (result == end(langs)) {
		cout << "Not found";
	}
	else {
		cout << result->age << endl;
	}*/
	/*cout << (*result).age << endl;
	cout << result->age << endl;*/
	return 0;
}