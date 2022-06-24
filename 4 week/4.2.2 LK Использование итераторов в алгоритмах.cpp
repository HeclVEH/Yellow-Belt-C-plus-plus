#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

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
	set<string> langs = { 
		"Pytnon", "C++","C", "Java","C#" 
	};
	cout << all_of(begin(langs), end(langs),
		[](const string& lang) {
			return lang[0] >= 'A' && lang[0] <= 'Z';
		});
	//remove(begin(langs), end(langs), "C");
	//auto it = min_element(begin(langs), end(langs));
	//auto it = max_element(begin(langs), end(langs));
	/*auto pair = minmax_element(begin(langs), end(langs));
	cout << *pair.first << *pair.second << endl;*/
	/*auto it = unique(begin(langs), end(langs));*/
	/*auto it = remove_if(begin(langs), end(langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});*/
	//langs.erase(it, end(langs));
	//PrintRange(begin(langs),end(langs));

	return 0;
}