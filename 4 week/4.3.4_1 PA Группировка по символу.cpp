#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    //pair<RandomIt, RandomIt> pair_it;
    /*return equal_range(range_begin, range_end, [](const string& str1, const string& str2) -> bool {
        return str1[0] < str2[0];
        }
    );*/
    string tmp1 = { prefix };
    auto low_it = lower_bound(range_begin, range_end, tmp1);
    auto next_char = static_cast<char>(prefix + 1);
    string tmp2 = { next_char };
    auto upp_it = lower_bound(range_begin, range_end, tmp2);
    return make_pair(low_it, upp_it);
}

void test_1() {
    const vector<string> sorted_strings = { "moscow", "murmansk", "negev", "vologda" };

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
        (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
        (z_result.second - begin(sorted_strings)) << endl;
}

void test_2() {
    const vector<string> sorted_strings = { "moscow", "murmansk", "negev", "vologda"};

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    test_1();
    //test_2();
    return 0;
}
