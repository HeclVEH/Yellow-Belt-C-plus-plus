#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int64_t> Vec_Data(N);	
	int64_t avg = 0, sum = 0;
	for (auto& i : Vec_Data) {
		cin >> i;
		sum += i;
	}
	avg = sum / N;
	vector<int64_t> Result_Data;
	for (auto i = 0; i < N; ++i) {
		if (Vec_Data[i] > avg)
			Result_Data.push_back(i);
	}
	cout << Result_Data.size() << endl;
	int i = 0;
	for (auto& item : Result_Data) {
		if (i != 0) {
			cout << " ";
		}
		++i;
		cout << item;
	}
	cout << endl;
	return 0;
}

/* 
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> temperatures(n);
	int sum = 0;
	for (int& temperature : temperatures) {
		cin >> temperature;
		sum += temperature;
	}

	int average = sum / n;
	vector<int> result_indices;
	for (int i = 0; i < n; ++i) {
		if (temperatures[i] > average) {
			result_indices.push_back(i);
		}
	}

	cout << result_indices.size() << endl;
	for (int result_index : result_indices) {
		cout << result_index << " ";
	}
	cout << endl;

	return 0;
} 
*/