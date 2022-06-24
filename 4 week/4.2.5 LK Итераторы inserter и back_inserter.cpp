#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iterator>

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
		cout << *it << ", ";
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
	vector<string> langs = {
		"Pytnon", "C++","C", "Java","C#"
	};

	/*vector<string> c_langs;
	copy_if(begin(langs), end(langs),
		back_inserter(c_langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});
	PrintRange(begin(c_langs), end(c_langs));*/

	set<int> a = { 1,3,8 };
	set<int> b = { 3,7,8 };
	set<int> res;
	set_intersection(begin(a), end(a), begin(b), end(b),
		inserter(res, end(res)));
	PrintRange(begin(res), end(res));


	return 0;
}