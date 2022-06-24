#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

//enum class Lang {
//    DE, FR, IT
//};
//
//struct Region {
//	string std_name;
//	string parent_std_name;
//	map<Lang, string> names;
//	int64_t population;
//};

bool operator<(const Region& lhs, const Region& rhs) {
    
    return (tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < 
        tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population));
}

bool operator==(const Region& lhs, const Region& rhs) {

    return (tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) ==
        tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population));
}

int FindMaxRepetitionCount(const vector<Region>& regions) {   
    if (regions.empty()) {
        return 0;
    }
    set<Region> setregion(regions.begin(), regions.end());
    set<int> s;
    for (const auto& item : setregion) {
        s.insert(count(begin(regions), end(regions), item));
    }
    return *s.rbegin();
}

//int main() {
//    cout << FindMaxRepetitionCount({
//        {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Russia",
//            "Eurasia",
//            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Russia",
//            "Eurasia",
//            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//            89
//        },
//        }) << endl;
//
//    cout << FindMaxRepetitionCount({
//        {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Russia",
//            "Eurasia",
//            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Moscow",
//            "Toulouse",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            31
//        },
//        }) << endl;
//
//    return 0;
//}
