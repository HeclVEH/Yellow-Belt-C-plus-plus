#include "synonyms.h"

#include <exception>
#include <iostream>
#include <vector>

using namespace std;

#include "tests.h"

int main() {
	TestAll();

	int q;
	cin >> q;

	Synonyms synonyms;
	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;
		if (operation_code == "ADD") {
			string first_word, second_word;
			AddSynomyns(synonyms, first_word, second_word);
		}
		else if (operation_code == "COUNT") {
			string word;
			cin >> word;
			cout << GetSynonymCount(synonyms, word) << endl;
		}
		else if (operation_code == "CHECK") {
			string first_word, second_word;
			cin >> first_word, second_word;
			if (AreSynonyms(synonyms, first_word, second_word)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}