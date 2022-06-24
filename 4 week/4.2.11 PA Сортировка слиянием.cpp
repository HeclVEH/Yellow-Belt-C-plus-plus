#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it = begin(elements) + elements.size() / 2;
    MergeSort2(begin(elements), it);
    MergeSort2(it, end(elements));
    merge(begin(elements), it, it, end(elements), range_begin);
}

template <typename RandomIt>
void MergeSort3(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 3) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it1 = begin(elements) + elements.size() / 3;
    auto it2 = it1 + elements.size() / 3;
    MergeSort3(begin(elements), it1);
    MergeSort3(it1, it2);
    vector<typename RandomIt::value_type> tmp;
    merge(begin(elements), it1, it1, it2, back_inserter(tmp));
    MergeSort3(it2, end(elements));
    merge(tmp.begin(), tmp.end(), it2, elements.end(), range_begin);
}

int main() {
    vector<int> v2 = { 6, 4, 7, 6, 4, 4, 0, 1 };
    MergeSort2(begin(v2), end(v2));
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> v3 = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
    MergeSort3(begin(v3), end(v3));
    for (int x : v3) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}