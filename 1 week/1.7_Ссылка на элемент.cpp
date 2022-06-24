#include <string>
#include <map>
#include <iostream>
using namespace std;

template<typename K, typename V>
V& GetRefStrict(map<K, V>& m, K value);

template<typename K, typename V>
V& GetRefStrict(map<K, V>& m, K value) {
	if (m.find(value) == m.end()) {
		throw runtime_error("Not exist");
	}
	return m[value];
}


int main() {
	try {
		map<int, string> m = { {0, "value"} };
		string& item = GetRefStrict(m, 0);
		item = "newvalue";
		cout << m[0] << endl; // выведет newvalue
	}
	catch (exception& s) {
		cout << s.what();
	}
	return 0;

}
