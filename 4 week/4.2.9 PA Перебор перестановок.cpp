#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> tmp_vec;
    while (num != 0) {
        tmp_vec.push_back(num);
        --num;
    }
    do {
        for (auto item : tmp_vec) {
            cout << item << " ";
        }
        cout << endl;
    }
    while (prev_permutation(tmp_vec.begin(), tmp_vec.end()));
    return 0;
}

//������� �� �������������

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//
//using namespace std;
//
//int main() {
//    int range_length;
//    cin >> range_length;
//    vector<int> permutation(range_length);
//
//    // iota             -> http://ru.cppreference.com/w/cpp/algorithm/iota
//    // ��������� �������� ��������������� ������������� ����������
//    // �������� ��������� ��������� ��������� ���, �������� �� ����� � ������
//    iota(permutation.rbegin(), permutation.rend(), 1);
//
//    // prev_permutation ->
//    //     http://ru.cppreference.com/w/cpp/algorithm/prev_permutation
//    // ����������� �������� � ���������� (�����������������) ������������,
//    // ���� ��� ����������, � ���������� true,
//    // ����� (���� �� ����������) - � ��������� (����������) � ���������� false
//    do {
//        for (int num : permutation) {
//            cout << num << ' ';
//        }
//        cout << endl;
//    } while (prev_permutation(permutation.begin(), permutation.end()));
//
//    return 0;
//}
