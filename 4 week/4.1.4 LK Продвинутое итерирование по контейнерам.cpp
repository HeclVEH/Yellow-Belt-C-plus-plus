#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Lang {
	string name;
	int age;
};

//using LangIt = vector<string>::iterator;

template <typename It>
void PrintRange(It range_begin, It range_end) {
	for (auto it = range_begin;
		it != range_end; ++it) {
		cout << *it << " ";
	}
}

template <typename It>
void PrintMapRange(It range_begin, It range_end) {
	for (auto it = range_begin;
		it != range_end; ++it) {
		cout << it->first << '/' << it->second << " ";
	}
}

int main() {
	set<string> langs = { "Pytnon", "C++","C", "Java","C#" };
	auto it = end(langs);
	while (--it != begin(langs)) {
		//--it;
		cout << *it << " ";
	}

	/*map<string, int> langs = {
		{"Pytnon", 26},
		{"C++", 34},
		{"C", 45},
		{"Java", 22},
		{"C#",17 }
	};
	auto it = langs.find("C++");
	PrintMapRange(begin(langs), it);
	cout << endl;
	PrintMapRange(it, end(langs));*/
	return 0;
}