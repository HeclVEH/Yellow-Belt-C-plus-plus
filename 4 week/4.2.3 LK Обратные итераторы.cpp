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
	vector<string> langs = {
		"Pytnon", "C++","C", "Java","C#"
	};

	sort(rbegin(langs), rend(langs));
	PrintRange(begin(langs), end(langs));

	/*auto it = find_if(rbegin(langs), rend(langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});
	cout << *it << endl;*/

	/*auto it = rbegin(langs);
	cout << *it << " ";
	++it;
	cout << *it << " ";*/

	//PrintRange(begin(langs), end(langs));
	//PrintRange(rbegin(langs), rend(langs));
	//cout << *rbegin(langs) << endl;
	//cout << *rend(langs) << endl;
	return 0;
}