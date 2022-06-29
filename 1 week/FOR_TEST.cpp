#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	vector<int> A = { 1,3,4,2,1,2,31,1,31,34 };
	int k = 0;
	for (int i = 0; i < A.size() - 1; ++i) {
		for (int j = 0; j < A.size() - 1 - k; ++j) {
			if (A[j + 1] < A[j]) {
				auto tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;				
			}
		}
		++k;
	}
	for (auto item : A) {
		cout << item << " ";
	}
	return 0;
}