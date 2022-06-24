#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
	cout << (-1 < 1u) << endl;
	return 0;
}

void ters(){
	vector<int> t = { -8,-7,3 };
	for (int i = 0; i < t.size(); ++i) {

	}
	int sum = 0;
	for (int x : t) {
		sum += x;
	}
	cout << sum / t.size();
}