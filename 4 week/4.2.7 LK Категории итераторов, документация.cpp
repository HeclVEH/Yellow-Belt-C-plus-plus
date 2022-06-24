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

	//vector<string> c_langs;
	//auto it = find_if(begin(langs), end(langs),
	//	[](const string& lang) {
	//		return lang[0] == 'C';
	//	});
	//cout << it - begin(langs) << endl;
	////PrintRange(begin(c_langs), end(c_langs));

	set<int> s = { 1,6,8,9 };
	auto it = s.find(6);
	//++it;
	PrintRange(next(it), end(s));
	//end(s) - begin(s);

	return 0;
}