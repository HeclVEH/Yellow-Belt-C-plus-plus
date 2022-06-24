#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int FindMaxRepetitionCount(const vector<int>& vec) {
	set<int> s;
	for (const auto& item : vec) {
		s.insert(count(begin(vec), end(vec), item));
	} 
	return *s.rbegin();
}

int main() {
	vector<int> v = { 0,0,0,0,4,5,6,7,5,5,5,5 };
	cout << FindMaxRepetitionCount(v);
	/*for (int i = 0; i < 50; ++i) {
		v.push_back(rand() % 10);
	}
	for (auto i : v) {
		cout << i << " ";
	}*/
	return 0;
}