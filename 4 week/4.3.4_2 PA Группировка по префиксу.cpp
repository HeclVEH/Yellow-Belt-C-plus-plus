#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
    //pair<RandomIt, RandomIt> pair_it;
    /*return equal_range(range_begin, range_end, [](const string& str1, const string& str2) -> bool {
        return str1[0] < str2[0];
        }
    );*/
    auto target = prefix;
    auto first_it = lower_bound(range_begin, range_end, target);
    ++target[prefix.size() - 1];
    auto second_it = lower_bound(range_begin, range_end, target);
    return make_pair(first_it, second_it);
    //return equal_range(range_begin, range_end, prefix);
}

int main() {
    const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

    const auto mo_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
        (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
        (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}
