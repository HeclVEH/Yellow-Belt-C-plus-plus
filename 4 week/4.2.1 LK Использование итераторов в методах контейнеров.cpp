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
	vector<string> langs = { "Pytnon", "C++","C", "Java","C#" };
	auto it = find(begin(langs), end(langs), "C++");
	langs.erase(it, end(langs));
	langs.insert(begin(langs), "C++");
	PrintRange(begin(langs), end(langs));	
	return 0;
}