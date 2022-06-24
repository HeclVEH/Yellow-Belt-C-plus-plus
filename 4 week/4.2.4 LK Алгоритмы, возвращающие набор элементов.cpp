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

	/*vector<string> c_langs(langs.size());
	auto it = copy_if(begin(langs), end(langs), begin(c_langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});
	PrintRange(begin(c_langs), it);*/

	set<int> a = { 1,8,3 };
	set<int> b = { 3,6,8 };
	vector<int> v;
	auto it = set_intersection(begin(a), end(a),
		begin(b), end(b), begin(v));
	PrintRange(begin(v), it);

	//auto it = partition(begin(langs), end(langs),
	//	[](const string& lang) {
	//		return lang[0] == 'C';
	//	});
	////PrintRange(begin(langs), end(langs));
	//PrintRange(begin(langs), it);
	
	return 0;
}