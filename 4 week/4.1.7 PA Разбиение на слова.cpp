#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    string tmp;
    auto it = s.begin();
    while (it != s.end()) {
        if (*it == ' ') {
            result.push_back(tmp);
            tmp.clear();
        }
        else {
            tmp += *it;
        }   
        ++it;
    }
    result.push_back(tmp);
    return result;
}

//������� �������������
//
//vector<string> SplitIntoWords(const string& str) {
//    // ������� ������, � ������� ����� ��������� �����
//    vector<string> result;
//
//    // ��� ��� ��������� ����� ������������ ������� �� �������� ����� ������
//    // str_begin ����� ��������� ������
//    auto str_begin = begin(str);
//    // str_end ������ ����� ��������� �� ����� ������ (������� �� �����������)
//    const auto str_end = end(str);
//
//    // � ����� ��� ������� ����������, ��� ��� ������������ ������ ��������� ��� �
//    // ������� break
//    while (true) {
//
//        // ������� ������ ������ � ������� ������� ������
//        auto it = find(str_begin, str_end, ' ');
//
//        // ������������ [str_begin, it) � ��������� �����
//        result.push_back(string(str_begin, it));
//
//        if (it == str_end) {
//            // ���� �������� ������ ���, ���� ���� ���������.
//            // ��������� ����� ��� ���������
//            break;
//        }
//        else {
//            // ����� ������ ������ ����� ������� � ������ ���������� �����.
//            // ���� � �������� str_begin
//            str_begin = it + 1;
//        }
//
//    }
//
//    return result;
//}


int main() {
    string s = "C Cpp Java Python";
    //string s = "CCpp dfgf gf f fg ad adf  adfasdfsdf adfasdf sd df asdf sadfsdJava Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
