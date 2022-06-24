#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

//template <typename T>
//void RemoveDuplicates(vector<T>& elements) {
//    set<T> tmp;
//    for (auto item : elements) {
//        tmp.insert(item);
//    }
//    elements.clear();
//    for (auto item : tmp) {
//        elements.push_back(item);
//    }
//}

//������� ������������� 
template <typename DataType>
void RemoveDuplicates(vector<DataType>& elements) {
    sort(begin(elements), end(elements));
    elements.erase(
        unique(begin(elements), end(elements)),
        elements.end());
}

int main() {
    vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
