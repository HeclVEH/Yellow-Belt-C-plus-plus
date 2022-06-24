#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Lang {
	string name;
	int age;
};

using LangIt = vector<string>::iterator;

template <typename It>
void PrintRange(It range_begin,	It range_end) {
	for (auto it = range_begin;
		it != range_end; ++it) {
		cout << *it << " ";
	}
}
int main() {
	vector<string> langs = {"Pytnon","C++",	"C","Java","C#"};
	auto border = find(begin(langs), end(langs), "C");
	PrintRange(begin(langs), border);
	//PrintRange(begin(langs), end(langs));
	//PrintRange(begin(langs[0]), end(langs[0]));
	//cout << end(langs)->name;
	/*for (auto it = begin(langs);
		it != end(langs); ++it) {
		cout << it->name << " ";
	}*/

	//auto result = find_if(
	//	begin(langs), end(langs),
	//	[](const Lang& lang) {
	//		return lang.name[0] == 'D';
	//	});
	////cout << langs[0].name << endl;

	//string lang = langs[1].name;
	//auto it = begin(lang);
	//cout << *it;
	//++it;
	//cout << *it;
	
	return 0;
}