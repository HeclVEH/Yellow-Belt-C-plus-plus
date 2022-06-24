#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

template <typename first, typename second>
pair<first, second> operator * (const pair<first, second>& p1,
								const pair<first, second>& p2);

template <typename key, typename value>
map<key, value> operator * (const map<key, value> t1, const map<key, value> t2);

template<typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2);

template <class  T>
auto Sqr(const T& x);

template <typename first, typename second>
pair<first, second> operator * (const pair<first, second>& p1, 
							   const pair<first, second>& p2) {
	first f = p1.first * p2.first;
	second s = p1.second * p2.second;
	return make_pair(f, s);
}

template <typename key, typename value> 
map<key, value> operator * (const map<key, value> t1, const map<key, value> t2) {
	map<key, value> tmp;
	for (auto item : t1) {
		tmp[item.first] = t1.at(item.first) * t2.at(item.first);
	}
	return tmp;
}

template<typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2) {
	vector<T> tmp;
	for (auto i = 0; i < v1.size(); ++i) {
		tmp.push_back(v1[i]*v2[i]);
	}
	return tmp;
}

template <class  T>
auto Sqr(const T& x) { 
	return x * x; 
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