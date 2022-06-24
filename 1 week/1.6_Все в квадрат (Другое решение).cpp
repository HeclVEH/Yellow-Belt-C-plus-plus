#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

template<typename T> 
T Sqr(const T& x);

template<typename F, typename S>
pair<F, S> Sqr(const pair<F, S>& p);

template<typename K, typename V>
map<K, V> Sqr(const map<K, V>& m);

template<typename T>
vector<T> Sqr(const vector<T>& v);

template<typename T>
T Sqr(const T& x) {
	return x * x;
}

template<typename F, typename S>
pair<F, S> Sqr(const pair<F, S>& p) {
	return make_pair(Sqr(p.first), Sqr(p.second));
}

template<typename K, typename V>
map<K, V> Sqr(const map<K, V>& m) {
	map<K, V> tmp;
	for (const auto& item : m) {
		tmp[item.first] = Sqr(item.second);
	}
	return tmp;
}

template<typename T>
vector<T> Sqr(const vector<T>& v) {
	vector<T> tmp;
	for (const auto& item : v) {
		tmp.push_back(Sqr(item));
	}
	return tmp;
}

int main() {
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	/*pair<double, int> p = { 2,4 };
	auto res = Sqr(p);
	cout << res.first << " " << res.second;*/

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}