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
	vector<int> s = { 1,2,7 };
	vector<int> t = { 1,2 };
	sort(begin(s), rend(s));	
	return 0;
}